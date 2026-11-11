#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#define FOR(i,a,b) for(int i = (a);i <= (b);++i)
#define REP(i,a,b) for(int i = (a);i >= (b);--i)
#define ll long long
static char stkk[200];
template<typename T>inline void output(T x){
    if(!x)return putchar('0'),void();
    if(x<0)x = ~x+1,putchar('-');
    int top = 0;
    for(;x;stkk[++top]=x%10^48,x/=10);
    for(;top;putchar(stkk[top--]));
}
template<typename T>inline void readx(T &x){
    x = 0;int y = 1;char c = getchar();
    for(;c<48||c>57;c = getchar())if(c=='-')y = -1;
    for(;c>=48&&c<=57;c = getchar())x = (x<<1)+(x<<3)+(c^48);
    x*=y;
}
const int N = 5e5+10;
static int n,ans;
static ll a[N],s[N],m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    readx(n),readx(m);
    FOR(i,1,n)readx(a[i]);
    std::sort(a+1,a+1+n);
    FOR(i,1,n)(s[i]=s[i-1])+=a[i];
    for(int i = 1,j = 1;i <= n;++i){
        for(;1ll*(i-j+1)*a[i]-(s[i]-s[j-1])>m;++j);
        ans = std::max(ans,i-j+1);
    }
    output(ans),putchar(10);
    return 0;
}