#include <bits/stdc++.h>


using namespace std;
int dp[20005][20005],aaa[20005],maxx[20005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>aaa[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=aaa[i];
        maxx[0]=max(maxx[0],aaa[i]);
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=dp[i-1][j];
            if(j-1>=0)
                dp[i][j]=max(dp[i][j-1]&aaa[i],dp[i][j]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
