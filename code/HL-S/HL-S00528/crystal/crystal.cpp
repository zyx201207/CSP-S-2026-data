#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[514114],sum[514114];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        while(l<r){
            mid=(l+r)/2;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    //    cout<<l<<" ";
    }
    cout<<ans;
    return 0;
}