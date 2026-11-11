#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 502;
const int MAXM = 1000002;

struct Edge
{
    int v;
    ll w;
};

int C,n,m,d,q;
ll w[MAXM];
ll dis[MAXN][MAXN];
vector <Edge> links[MAXM];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> C >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
        cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        int cc;
        cin >> cc;
        while(cc--)
        {
            int x; ll v;
            cin >> x >> v;
            links[x].push_back({i,v});
        }
    }

    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i <= m;i++)
    {
        auto &link = links[i];
        for(int j = 0;j < link.size();j++)
        {
            int u = link[j].v;
            for(int k = j + 1;k < link.size();k++)
            {
                int v = link[k].v;
                ll val = link[j].w + link[k].w;
                dis[u][v] = min(dis[u][v],val);
                dis[v][u] = min(dis[v][u],val);
            }
        }
    }

    for(int i = 1;i <= n;i++)
        dis[i][i] = 0;
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    while(q--)
    {
        int s,t;
        cin >> s >> t;
        ll minv = 0x3f3f3f3f3f3f3f3fll;
        for(auto &curs : links[s])
            for(auto &curt : links[t])
                minv = min(minv,dis[curs.v][curt.v] + curs.w + curt.w);
        cout << minv + w[s] + w[t] << '\n';
    }
    
    return 0;
}
