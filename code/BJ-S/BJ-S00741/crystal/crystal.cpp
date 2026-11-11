#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=1;
ll a[500005],pre[500005];
ll bound(const ll &p){
    ll mid,ans=p,l=1,r=p;
    while(l<=r){
        mid=l+r>>1;
        if((p-mid+1)*a[p]-pre[p]+pre[mid-1]<=m){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++) pre[i]=a[i]+pre[i-1];
    for(ll i=1;i<=n;i++){
        ll j=bound(i);
        ans=max(i-j+1,ans);
    }
    cout<<ans;
    return 0;
}