#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>


using namespace std;


const int maxn = 505;
struct bign{
  int len, s[maxn];
  bign() {
    memset(s, 0, sizeof(s));
    len = 1;
  }


  bign(int num) {
    *this = num;
  }


  bign(const char* num) {
    *this = num;
  }


  bign operator = (int num) {
    char s[maxn];
    sprintf(s, "%d", num);
    *this = s;
    return *this;
  }


  bign operator = (const char* num) {
    len = strlen(num);
    for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
    return *this;
  }


  string str() const {
    string res = "";
    for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
    if(res == "") res = "0";
    return res;
  }


  bign operator + (const bign& b) const{
    bign c;
    c.len = 0;
    for(int i = 0, g = 0; g || i < max(len, b.len); i++) {
      int x = g;
      if(i < len) x += s[i];
      if(i < b.len) x += b.s[i];
      c.s[c.len++] = x % 10;
      g = x / 10;
    }
    return c;
  }


  void clean() {
    while(len > 1 && !s[len-1]) len--;
  }


  bign operator * (const bign& b) {
    bign c; c.len = len + b.len;
    for(int i = 0; i < len; i++)
      for(int j = 0; j < b.len; j++)
        c.s[i+j] += s[i] * b.s[j];
    for(int i = 0; i < c.len-1; i++){
      c.s[i+1] += c.s[i] / 10;
      c.s[i] %= 10;
    }
    c.clean();
    return c;
  }


  bign operator - (const bign& b) {//该算法仅支持  大的数-小的数
    bign c; c.len = 0;
    for(int i = 0, g = 0; i < len; i++) {
      int x = s[i] - g;
      if(i < b.len) x -= b.s[i];
      if(x >= 0) g = 0;
      else {
        g = 1;
        x += 10;
      }
      c.s[c.len++] = x;
    }
    c.clean();
    return c;
  }


  bool operator < (const bign& b) const{//可选
    if(len != b.len) return len < b.len;
    for(int i = len-1; i >= 0; i--)
      if(s[i] != b.s[i]) return s[i] < b.s[i];
    return false;
  }


  bool operator > (const bign& b) const{//可选
    return b < *this;
  }


  bool operator <= (const bign& b) {//可选
    return !(b < *this);
  }


  bool operator == (const bign& b) {//可选
    return !(b < *this) && !(*this < b);
  }


  bign operator += (const bign& b) {//可选
    *this = *this + b;
    return *this;
  }
};
struct bign a,b,c;
int main()
{
    char strA[505],strB[505];
    while(scanf("%s %s",strA,strB)!=EOF)
    {
        a=strA;b=strB;
        if(a<b)
        {
            printf("-%s\n",(b-a).str().c_str());
        }
        else
        {
            printf("%s\n",(a-b).str().c_str());
        }
    }
    return 0;
}//Parsed in 0.189 seconds
