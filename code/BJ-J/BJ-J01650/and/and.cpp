#include <bits/stdc++.h>
using namespace std;
const int N=2e3+7;
int dp[N][N];
int a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=(1<<30)-1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
