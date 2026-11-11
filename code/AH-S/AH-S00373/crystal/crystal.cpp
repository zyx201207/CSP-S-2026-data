#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],b[500005],m,n;
bool ck(ll l,ll r){
    return (r-l+1)*a[r]+b[r]+b[l-1]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll ans=-1e18;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        ll l=0,r=i;
        while(l+1<r){
            ll mid=(l+r)/2;
            if(ck(mid,i)) r=mid;
            else l=mid;
            //cout<<mid<<" "<<r<<" "<<l<<endl;
            ans=max(ans,r-l+1);
            //cout<<ans<<endl;
        }
     }
    cout<<ans;
    return 0;
}
