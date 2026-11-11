
#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long dp[200010][200010][5],n,m,a[200010];
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }memset(dp,0,sizeof(dp));
    for(LL i=1;i<=n;i++){
        dp[i][1][1]=a[i];
        for(LL j=1;j<=m;j++){
            dp[i][j][1]=max(dp[i-1][j-1][1]&a[i],dp[i-1][j-1][0]&a[i]);
            dp[i][j][0]=max(dp[i-1][j][1],dp[i-1][j][0]);
        }
    }cout<<max(dp[n][m][1],dp[n][m][0]);
    return 0;
}
