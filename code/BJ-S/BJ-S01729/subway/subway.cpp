#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
struct node{
    int v,w;
};
vector<node> g[N];
int w[N],dis[505][505];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _c_,n,m,_d_,q;
    cin>>_c_>>n>>m>>_d_>>q;
    for (int i=1;i<=m;i++)
        cin>>w[i];
    for (int i=1;i<=n;i++)
    {
        int k,a,t;
        cin>>k;
        while (k--)
        {
            cin>>a>>t;
            g[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for (int i=1;i<=n;i++)
        dis[i][i]=0;
    for (int k=1;k<=m;k++)
        for (int i=0;i<(int)g[k].size();i++)
            for (int j=0;j<(int)g[k].size();j++)
            {
                int u=g[k][i].v,v=g[k][j].v;
                dis[u][v]=min(dis[u][v],g[k][i].w+g[k][j].w);
            }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while (q--)
    {
        int x,y,ans=1e18;
        cin>>x>>y;
        for (int i=0;i<(int)g[x].size();i++)
            for (int j=0;j<(int)g[y].size();j++)
                ans=min(ans,w[x]+g[x][i].w+dis[g[x][i].v][g[y][j].v]+g[y][j].w+w[y]);
        cout<<ans<<"\n";
    }
    return 0;
}