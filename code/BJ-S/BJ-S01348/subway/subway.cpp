#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct node
{
    int y;
    long long w;
};
vector<node> g[500010];
int w[500010],k[500010];
long long f[510][510];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int a;
            long long t;
            cin>>a>>t;
            g[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int x=0;x<g[i].size();x++)
        {
            int u=g[i][x].y;
            long long w1=g[i][x].w;
            for(int y=0;y<g[i].size();y++)
            {
                int v=g[i][y].y;
                long long w2=g[i][y].w;
                if(u==v)
                {
                    f[u][v]=0;
                    continue;
                }
                f[u][v]=f[v][u]=min(f[u][v],w1+w2);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        long long ans=1e18;
        cin>>x>>y;
        for(int i=0;i<g[x].size();i++)
        {
            int u=g[x][i].y;
            long long w1=g[x][i].w;
            for(int j=0;j<g[y].size();j++)
            {
                int v=g[y][j].y;
                long long w2=g[y][j].w;
                ans=min(ans,f[u][v]+w1+w2+w[x]+w[y]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
