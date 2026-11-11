#include <bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m;
long long a[N];
long long dp[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int j=2;j<=n;j++){
        dp[j-1]=0;
        for(int i=j;i<=n;i++){
            if(a[i]==a[i-1]) dp[i]=dp[i-1];
            else dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-j+1);
        }
        for(int i=j-1;i<=n;i++){
            if(dp[i]<=m) ans=max(ans,i-j+2);
        }
    }
    cout<<ans;
    return 0;
}
