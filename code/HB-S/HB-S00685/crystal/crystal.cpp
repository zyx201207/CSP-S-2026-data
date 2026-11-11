#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n;
ll m,a[maxn];
ll sum[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    a[n+1]=-1e18;
    ll ans=1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]) continue;
        ll l=1,r=i,k=i;
        while(l<r){
            ll mid=(l+r)>>1;
            if((1ll*(i-mid)*a[i]-sum[i-1]+sum[mid-1])<=m){
                k=mid;
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,1ll*i-k+1);
    }
    cout<<ans;
    return 0;
}