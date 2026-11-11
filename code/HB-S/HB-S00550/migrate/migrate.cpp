#include <bits/stdc++.h>
#define int long long
using namespace std;

int c,t,n,d,x[305];
int dp[305][305][305],vis[305][305];


signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                vis[i][j]=0;
                for(int k=1;k<=n;k++)
                    dp[i][j][k]=0;
            }
                
        //枚举直飞
        for(int u=1;u<n;u++)
        {
            dp[u][u][0]=1;
            vis[u][u]=1;
            for(int v=u+1;v<=n;v++)
            {
                if(x[v]-x[u]<=d)dp[u][v][1]=1,vis[u][v]=1;
            }
        }
        dp[n][n][0]=1;
        vis[n][n]=1;
        for(int dist=2;dist<=n;dist++)
        {
            for(int u=1;u<n;u++)
            {
                for(int v=u+2;v<=n;v++)
                {
                    // if(vis[u][v])continue;
                    for(int mid=u+1;mid<v;mid++)
                    {
                        if(x[mid]-x[u]>d || x[v]-x[mid]>d)continue;
                        for(int xx=1;xx<dist;xx++)
                        {
                            if(dp[u][mid][xx]*dp[mid][v][dist-xx])vis[u][v]=1;
                            dp[u][v][dist]+=dp[u][mid][xx]*dp[mid][v][dist-xx];
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int u=1;u<=n;u++)
        {
            for(int v=u+1;v<=n;v++)
            {
                for(int dist=1;dist<=n;dist++)
                {
                    if(dp[u][v][dist]!=0 && dp[u][v][dist]!=2)break;
                    if(dp[u][v][dist]==2)
                    {
                        ans++;
                        // printf("u:%lld,v:%lld,dis:%lld\n",u,v,dist);
                        break;
                    }
                }
                
            }
        }
        cout<<ans<<"\n";
        // printf("\n");
    }

    return 0;
}