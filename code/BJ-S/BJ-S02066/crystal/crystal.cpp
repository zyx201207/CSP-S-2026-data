#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const ll N=5e5;
ll a[N+5],sum[N+5];
ll n,m,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(ll i=1;i<=n;i++){
        ll l=1,r=i,id=-1;
        while(l<=r){
            ll mid=l+r>>1;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])>m){
                l=mid+1;
            }else{
                id=mid;
                r=mid-1;
            }
        }
        ans=max(ans,i-id+1);
    }
    cout<<ans;
    return 0;
}
