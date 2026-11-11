#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2005];
int dp[2005][2005];
int main(){
    freopen("ans.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {

        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j-1]^a[i]);
        }
    }
    cout << dp[n][m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
