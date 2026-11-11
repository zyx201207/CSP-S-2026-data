#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define il inline
#define gc() getchar()
il ll read(){
    ll x=0,f=1;char ch=gc();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=gc();
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return x*f;
}
const int N=5e5+5;
ll a[N],s[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n=read(),m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
    ll l=1;
    ll ans=1;
    ll sum=0;
    for(ll r=1;r<=n;++r){
        sum=(r-l+1)*a[r]-(s[r]-s[l-1]);
        while(l<=r&&sum>m){
            sum-=(a[r]-a[l]);
            ++l;
        }
        if(sum<=m) ans=max(ans,r-l+1);
    }
    printf("%lld\n",ans);
    return 0;
}
