#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010],sum[500010];
int main(){
    cin.tie(0),ios::sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        int l=1,r=i,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(sum[i]-sum[mid-1]+m>=a[i]*(ll)(i-mid+1))r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}