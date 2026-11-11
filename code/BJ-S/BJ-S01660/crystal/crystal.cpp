#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[500001],n,m,a[500001],l=1,r,mid,ans,res;
bool p(ll l,ll r){return a[r]*(r-l+1)-sum[r]+sum[l-1]<=m;}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for (ll i=1;i<=n;i++){
        l=res=1,r=i;
        while (l<=r){
            mid=(l+r)/2;
            if (p(mid,i)){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans;
    return 0;
}