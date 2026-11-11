#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500020];
bool check(int k){
    int ans=0,sum=0;
    for (int i=1;i<k;i++) sum+=(a[k]-a[i]);
    ans=sum;
    // cout<<k<<" :"<<sum<<" ";
    for (int i=k+1;i<=n;i++){
        int j=i-k;
        sum=sum+k*(a[i]-a[i-1])-(a[i-1]-a[j]);
        // cout<<sum<<" ";
        ans=min(ans,sum);
    }
    // cout<<"\n";
    return ans<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++ )cin>>a[i];
    sort(a+1,a+1+n);
    int l=1,r=n,ans=114514;
    while(l<=r){
        int mid=(l+r)/2;
        if (check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans<<"\n";
    return 0;
}