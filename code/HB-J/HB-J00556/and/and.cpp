#include <bits/stdc++.h>

using namespace std;
const int MAX=1e4+5;
int a[MAX];
int dp[MAX][MAX];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][1]=a[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i][j-1]&a[i]);
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
