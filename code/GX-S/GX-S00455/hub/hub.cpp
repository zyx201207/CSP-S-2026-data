#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LOVEN = 1001314;
const ll INF = 1e18;
int c, t, n;
ll k, dis[LOVEN], asn = 0;
bool build[LOVEN] = {false}, vis[LOVEN];
struct Edge
{
    ll w;
    int to;
};
vector<Edge> g[LOVEN];
priority_queue<Edge> q;

inline ll DIJ(int s)
{
    ll res = INF;
    for(int i = 1; i <= n; ++i)
    {
        dis[i] = INF;
        vis[i] = false;
    }
    dis[s] = 0;
    q.push({dis[s], s});
    while(!q.empty())
    {
        int u = q.top().to;
        ll dd = q.top().w;
        q.pop();
        if(build[u]){res = min(res, dd);
        continue;
        }
        if(vis[u]) continue;
        vis[u] = true;
        for(auto e :g[u])
        {
            int v = e.to;
            ll w = e.w;
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back({1, v});
            g[v].push_back({1, u});
        }
        for(ll mask = pow(2, k - 1); mask < (1 << n); ++mask)
        {
            int cnt1 = __builtin_popcount(mask);
            if(cnt1 < k) continue;
            else if(cnt1 > k) continue;

            for(int i = 1; i <= n; ++i)
            {
                build[i] = false;
                if( (mask >> (i - 1)) && 1 ) build[i] = true;
            }
            ll res = 0;
            for(int i = 1; i <= n; ++i)
            {
                ll dd = DIJ(i);
                res = max(res, dd);
            }
            asn = min(asn, res);
        }
        cout << asn << "\n";
        for(int i = 1; i <= n; ++i)
        {
            g[i].clear();
            build[i] = false;
            dis[i] = INF;
        }
        asn = INF;
    }
    return 0;
}
