#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 5;
const int MAXM = 5e5 + 12;
int c,n,m,d,q;
long long dis[MAXN][MAXN];
struct Edge{
    int v,w;
};
vector<Edge> E[MAXM];
long long w[MAXM];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++) cin >> w[i];
    for (int i=1;i<=n;i++)
    {
        int k;cin >> k;
        while (k--)
        {
            int a,t;cin >> a >> t;
            E[a].push_back({i,t});
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j) dis[i][j] = 1e18;
    for (int u=1;u<=m;u++)
    {
        for (int i=0;i<E[u].size();i++)
            for (int j=i+1;j<E[u].size();j++)
            {
                int x = E[u][i].v,y = E[u][j].v;
                long long w = E[u][i].w + E[u][j].w;
                dis[x][y] = min(dis[x][y],w);
                dis[y][x] = min(dis[y][x],w);
            }
    }
    for (int t=1;t<=n;t++)
        for (int u=1;u<=n;u++)
            for (int v=1;v<=n;v++)
                dis[u][v] = min(dis[u][v],dis[u][t]+dis[t][v]);
    while (q--)
    {
        int x,y;cin >> x >> y;
        long long ans = 1e18;
        for (int i=0;i<E[x].size();i++)
            for (int j=0;j<E[y].size();j++)
                ans = min(ans,w[x]+w[y]+E[x][i].w+E[y][j].w+dis[E[x][i].v][E[y][j].v]);
        cout << ans << '\n';
    }
    return 0;
}