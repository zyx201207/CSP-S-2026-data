#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define getc getchar_unlocked()
#define putc putchar_unlocked
ll re(){
    ll res=0;bool s=0;char c=getc;
    for(;!isdigit(c);c=getc) s|=c=='-';
    for(;isdigit(c);c=getc) res=(res<<3)+(res<<1)+(c-'0');
    return s?-res:res;
}
void wr(ll x){
    if(x<0) putc('-'),x=-x;
    if(x>9) wr(x/10);
    putc(x%10+'0');
}
#define rep(i,a,b) for(int i=(a);i<=(ll)(b);++i)
#define max(a,b) (a>b?a:b)
const int maxn=5e5+10;



ll n,m;
unsigned a[maxn];
unsigned dp[maxn];
int main(){
    #if 1
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    #endif
    n=re();m=re();
    rep(i,1,n) a[i]=re();
    rep(i,1,n) dp[i]=re();
    rep(i,2,m)
        for(int j=n;j>=1;j--)
        {
            int res=0;
            rep(k,1,j-1)
                res=max(res,dp[k] & a[j]);
            dp[j]=res;
        }

    wr(dp[n]);
    return 0;
}
