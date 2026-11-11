#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+5;
ll n,m,a[N],s[N];
ll find(ll i){
    ll l=1,r=i,ans=i;
    while(l<=r){
        ll mid=(l+r)>>1;
        if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)r=mid-1,ans=mid;
        else l=mid+1;
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans=max(ans,i-find(i)+1);
    }
    cout<<ans<<'\n';
    return 0;
}