#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int r,t;
};
struct node1
{
    int v,t;
};
int w[500005];
vector<node>ga[500005];
vector<node1>g[505];
bool vis[505];
int dfs(int u,int c,int t)
{
    if(u==c)return t;
    vis[u]=true;
    int mint=1e11;
    for(int i=0;i<g[u].size();i++)
    {
        if(vis[g[u][i].v])continue;
        mint=min(mint,dfs(g[u][i].v,c,t+g[u][i].t));
    }
    vis[u]=false;
    return mint;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            ga[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<ga[i].size();j++)
        {
            for(int k=0;k<j;k++)
            {
                g[ga[i][j].r].push_back({ga[i][k].r,ga[i][j].t+ga[i][k].t});
                g[ga[i][k].r].push_back({ga[i][j].r,ga[i][j].t+ga[i][k].t});
            }
        }
    }
    while(q--)
    {
        int x,y,mint=1e11;
        cin>>x>>y;
        for(int i=0;i<ga[x].size();i++)
        {
            for(int j=0;j<ga[y].size();j++)
            {
                for(int k=1;k<=n;k++)vis[k]=0;
                mint=min(mint,dfs(ga[x][i].r,ga[y][j].r,0)+ga[x][i].t+ga[y][j].t);
            }
        }
        cout<<mint+w[x]+w[y]<<'\n';
    }
}
