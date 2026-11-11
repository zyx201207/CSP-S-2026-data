#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int w[N];
//vector<vector <int> > dp;
int dp[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,t;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    memset(dp,N,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        for(int j=1;j<=t;j++)
        {
            int v,w;
            cin>>v>>w;
            dp[m+i][v]=w;
            dp[v][m+i]=w;
        }
    }
    for(int u=1;u<=m+n;u++)
    {
        for(int v=1;v<=m+n;v++)
        {
            for(int k=1;k<=m+n;k++)
            {
                if(dp[u][k]!=INT_MAX&&dp[k][v]!=INT_MAX)
                {

                    dp[u][v]=min(dp[u][v],dp[u][k]+dp[k][v]);
                    dp[v][u]=dp[u][v];
                }
            }
        }
    }
    int x;
    int y;
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        cout<<dp[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
