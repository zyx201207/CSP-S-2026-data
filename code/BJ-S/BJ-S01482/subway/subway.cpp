#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 1000;
int c, n, m, d, q, l, r, w[N]; ll dis[N];
vector<pii> e[N]; bool vis[N], f=1;
void dij(int s)
{
    memset(dis, 0x3f, sizeof dis);
    vis[s] = 1; dis[s] = 0;
    priority_queue<pii> q;
    q.push({0, s});
    while(!q.empty())
    {
        int u = q.top().S; q.pop();
        for(pii x : e[u])
        {
            int v = x.F, w = x.S;
            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1; i<=m; i++) cin >> w[i];
    for(int i=1, k; i<=n; i++)
    {
        cin >> k;
        for(int j=1, a, t; j<=k; j++)
        {
            cin >> a >> t;
            e[m+i].push_back({a, t});
            e[a].push_back({m+i, t});
        }
    }
    while(q--)
    {
        cin >> l >> r;
        dij(l);
        cout << w[l] + w[r] + dis[r] << '\n';
    }
    return 0;
}
