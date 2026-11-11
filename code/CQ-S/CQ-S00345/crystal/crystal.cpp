#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],dq[500005];
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=0,sum=0,ans=0;
    for(int i=1;i<=n;i++){
        sum+=(r-l+1)*(a[i]-a[i-1]);
        dq[++r]=a[i];
        while(l<=r&&sum>m)sum-=a[i]-dq[l],l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}