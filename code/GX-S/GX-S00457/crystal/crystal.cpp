#define pc putchar
#define gc getchar
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
    ll x=0;int f=1;char ch=gc();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=gc();}
    while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=gc();
    return x*f;
}
void write(ll x){
    if(x<0) pc('-'),x=-x;
    if(x>=10) write(x/10);
    pc(x%10+'0');
}
#define int ll
const int N=5e5+120;
ll n,m,a[N],s[N];
ll ans=0;
void solve(){
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
   // write(n),pc('\n'),write(m),pc('\n');
    sort(a+1LL,a+n+1LL);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        int l=1LL,r=i;
        if(a[i]*i-s[i]<=m){
            ans=max(ans,i);
            continue;
        }
        while(l<r){
            ll mid=(l+r)>>1LL;
            ll sum=(a[i]*(i-mid+1LL)-s[i]+s[mid-1LL]);
            if(sum>m) l=mid+1LL;
            else r=mid;
        }
        //if(i-l+1LL>ans){
            //write(i),pc(' '),write(i-l+1LL),pc(' '),write(ans),pc('\n');
        //}
        ans=max(i-l+1LL,ans);
    }
    write(ans),pc('\n');
    return;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int __=1;
    while(__--) solve();
    return 0;
}
