#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500050],b[500050],c[500050];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=n;i>=1;i--){
        b[i]=b[i+1]+a[i]-a[i-1];
        c[i]=c[i+1]+b[i];
    }
    // for(ll i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
    // for(ll i=1;i<=n;i++)cout<<c[i]<<" ";cout<<endl;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll l=1,r=i;
        while(l<r){
            ll mid=(l+r)>>1;
            // cout<<mid<<"-"<<i<<":"<<c[mid+1]-c[i+1]-(i-mid)*b[i+1]<<endl;
            if(c[mid+1]-c[i+1]-(i-mid)*b[i+1]<=m)r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}