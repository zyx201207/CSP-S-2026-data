#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[500001],sum[500001];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=2;i<=n;i++){
        int l=1,r=i-1,res=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(((i-mid)*a[i]-sum[i-1]+sum[mid-1])<=m)r=mid-1,res=i-mid;
            else l=mid+1;
        }
        ans=max(ans,res+1);
    }
    cout<<ans;
    return 0;
}