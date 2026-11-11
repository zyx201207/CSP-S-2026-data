#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,maxans;
ll a[N],sum[N],dis[N];
vector<ll> vec;
bool chk(ll v,ll k){
    if(v*a[k]-sum[k]+sum[k-v]<=m) return true;
    return false;
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    //for(ll i=1;i<=n;i++) cout<<sum[i]<<" ";
    //cout<<"\n";
    for(ll i=1;i<=n;i++){
        ll l=1,r=i,ans=1;
        while(l<=r){
            //cout<<"l: "<<l<<" r: "<<r<<"\n";
            ll mid=(l+r)>>1;
            if(chk(mid,i)){
                l=mid+1;
                ans=mid;
                //cout<<"ans: "<<ans;
            }else r=mid-1;
        }
        maxans=max(maxans,ans);
    }
    cout<<maxans;
    return 0;

}
