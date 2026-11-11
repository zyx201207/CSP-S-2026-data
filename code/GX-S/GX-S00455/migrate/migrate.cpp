#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LOVEN = 1001314;
const ll INF = 1e18;
int c, t, n;
ll d, x[LOVEN], dis[LOVEN], asn = 0, js[LOVEN];
bool vis[LOVEN] = {false};
struct Edge
{
    ll w;
    int to;
    bool operator < (const Edge& oth) const
    {
        return w > oth.w;
    };
};
vector<Edge> g[LOVEN];
priority_queue<Edge> q;
inline void DIJ(int s)
{
    for(int i = 1; i <= n; ++i)
    {
        dis[i] = INF;
        vis[i] = false;
        js[i] = 1;
    }
    dis[s] = 0;
    q.push({dis[s], s});
    while(!q.empty())
    {
        int u = q.top().to;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto e :g[u])
        {
            int v = e.to;
            ll w = e.w;
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                js[v] = js[u];
                q.push({dis[v], v});
            }
            else if(dis[u] + w == dis[v])
            {
                js[v] += js[u];
                continue;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1; i <= n; ++i)
        {
            cin >> x[i];
        }
        for(int i = 1; i < n; ++i)
        {
            for(int j = i + 1; j <= n; ++j)
            {
                if(abs(x[j] - x[i]) <= d)
                {
                    g[i].push_back({1ll, j});
                }
            }
        }
        for(int i = 1; i < n; ++i)
        {
            DIJ(i);
            for(int j = i + 1; j <= n; ++j)
            {
                if(js[j] == 2)
                {
                    ++asn;
                }
            }
        }
        cout << asn << "\n";
        for(int i = 1; i <= n; ++i)
        {
            g[i].clear();
            x[i] = INF;
        }
        while(!q.empty()) q.pop();
        asn = 0;
    }
    return 0;
}
