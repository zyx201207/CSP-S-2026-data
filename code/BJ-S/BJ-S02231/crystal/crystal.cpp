#include<bits/stdc++.h>
#define ll long long
#define MAXN 500005
#define inf 0x3f3f3f3f
using namespace std;
ll n,m,ans,a[MAXN],f[MAXN];
ll gh(ll x){
    ll l=1,r=x+1;
    while(l<r){
        ll mid=(l+r)/2;
        ll cnt=f[x-1]-f[mid-1];
        if(a[x]*(x-mid)-cnt>m)
            l=mid+1;
        else
            r=mid;
    }
    return x-l+1;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        f[i]=f[i-1]+a[i];
    for(int i=1;i<=n;i++)
        ans=max(ans,gh(i));
    cout<<ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll t;
    t=1;
    while(t--)
        solve();
    return 0;
}
