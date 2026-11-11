#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LOVEM = 500520;
const int LOVEN = 520;
const int LOVEPO = 501314;
const int LOVEQ = 101314;
const ll INF = 1e18;
int c, n, m, d, Q;
int st[LOVEQ], ed[LOVEQ];
ll walk[LOVEM], dis[LOVEPO], asn[LOVEQ];
bool vis[LOVEPO] = {false};
struct Edge
{
    ll w;
    int to;
    bool operator < (const Edge& oth) const
    {
        return w > oth.w;
    };
};
vector<Edge> g[LOVEPO];
priority_queue<Edge> q;
inline void DIJ(int s)
{
    for(int i = 1; i <= n + m + 8; ++i)
    {
        dis[i] = INF;
        vis[i] = false;
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
                q.push({dis[v], v});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> Q;
    for(int i = 1; i <= m; ++i)
    {
        cin >>walk[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        int station, line = m + i;
        cin >> station;
        for(int j = 1; j <= station; ++j)
        {
            int idx; ll w;
            cin >> idx >> w;
            g[idx].push_back({w, line});
            g[line].push_back({w, idx});
        }
    }
    for(int i = 1; i <= Q; ++i)
    {
        cin >> st[i] >> ed[i];
        asn[i] =  INF;
    }
    if(Q <= 100 || Q < n)
    {
        //cout << "Q=" << Q << " calc by Query\n";
        for(int i = 1; i <= Q; ++i)
        {
            DIJ(st[i]);
            ll res = 0;
            res = walk[st[i]] + walk[ed[i]] + dis[ed[i]];
            cout << res << "\n";
        }
        return 0;
    }
    else
    {
        //cout << "calc by Line\n";
        for(int line = m + 1; line <= m + n; ++line)
        {
            DIJ(line);
            for(int i = 1; i <= Q; ++i)
            {
                asn[i] = min(asn[i], dis[st[i]] + dis[ed[i]]);
            }
        }
        for(int i = 1; i <= Q; ++i)
        {
            asn[i] += walk[st[i]] + walk[ed[i]];
            cout << asn[i] << "\n";
        }
        return 0;
    }
    return 0;
}
