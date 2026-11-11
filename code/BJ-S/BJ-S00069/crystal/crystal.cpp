#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],sum[N],n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=0;
    for(ll i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        ll l=0,r=i-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(a[i]*(i-mid)-(sum[i]-sum[mid])<=m) r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-l);
        // cout<<a[i]*(i-0)-(sum[i]-sum[0])<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}
//Oct31==Dec25?
