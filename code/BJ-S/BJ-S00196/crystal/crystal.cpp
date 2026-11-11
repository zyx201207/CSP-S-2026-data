#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],n,m,dp[1000005],h[1000005],ans=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+1;
        h[i]=(a[i]-a[i-1])*dp[i-1]+h[i-1];
        while(h[i]>m){
            h[i]-=(a[i]-a[i-dp[i]+1]),dp[i]--;
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
