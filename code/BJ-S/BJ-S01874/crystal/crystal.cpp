#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],sum[500010];
bool check(ll s,ll e){
    return a[e]*(e-s)-sum[e-1]+sum[s-1]<=m;
}
ll bs(ll e){
    ll l=1,r=e,ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid,e))
            ans=mid,r=mid-1;
        else l=mid+1;
    }
    return e-ans+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,bs(i));
    cout<<ans;
    return 0;
}
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
