#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v,w;
};
long long dist[505][505];
vector<node> from[500005];
int a[500005],g[505][505],n,m,d,c,q;
bool vis[505];
void dij(int x)
{
    memset(vis,false,sizeof(vis));
    dist[x][x]=0;
    for (int i=1;i<=n;i++)
    {
        int t=-1;
        for (int j=1;j<=n;j++)
        {
            if (!vis[j]&&(t==-1||dist[x][j]<dist[x][t]))
            {
                t=j;
            }
        }
        if (t==-1)
        {
            break;
        }
        vis[t]=true;
        for (int j=1;j<=n;j++)
        {
            if (g[t][j]!=2e9&&dist[x][t]+g[t][j]<dist[x][j])
            {
                dist[x][j]=dist[x][t]+g[t][j];
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            g[i][j]=2e9;
        }
    }
    for (int i=1;i<=n;i++)
    {
        int len;
        cin>>len;
        for (int j=1;j<=len;j++)
        {
            int x,y;
            cin>>x>>y;
            for (int k=0;k<from[x].size();k++)
            {
                int v=from[x][k].v,w=from[x][k].w;
                g[i][v]=min(g[i][v],w+y);
                g[v][i]=min(g[v][i],w+y);
            }
            from[x].push_back({i,y});
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            dist[i][j]=1e18;
        }
        dij(i);
    }
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        long long ans=1e18;
        for (int i=0;i<from[x].size();i++)
        {
            for (int j=0;j<from[y].size();j++)
            {
                int u=from[x][i].v,w1=from[x][i].w,v=from[y][j].v,w2=from[y][j].w;
                ans=min(ans,dist[u][v]+a[x]+a[y]+w1+w2);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}