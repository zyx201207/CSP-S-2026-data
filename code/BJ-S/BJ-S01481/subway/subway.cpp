#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500500],a[510][500500],t[510][500500];
int dp[100][100];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
        for(int j=1;j<=a[i][0];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
             dp[i][j]=-1;
        }
        dp[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i][0];j++)
        {
             for(int k=j+1;k<=a[i][0];k++)
             {
                if(dp[a[i][j]][a[i][k]]==-1)
                {
                    dp[a[i][j]][a[i][k]]=t[i][j]+t[i][k];
                }
                else
                {
                    dp[a[i][j]][a[i][k]]=min(dp[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
                }
                dp[a[i][k]][a[i][j]]=dp[a[i][j]][a[i][k]];
             }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(dp[k][j]!=-1&&dp[i][k]!=-1)
                {
                    if(dp[i][j]==-1)
                    {
                        dp[i][j]=dp[i][k]+dp[k][j];
                    }
                    else
                    {
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                    }
                    dp[j][i]=dp[i][j];
                }
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<dp[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
