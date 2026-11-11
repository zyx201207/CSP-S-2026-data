#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
struct node
{
    int v, w;
};
bool operator< (const node xx, const node yy)
{
    return xx.w > yy.w;
}
int c, t, n, d, x[N], cnt[N], vis[N], dis[N];
vector<node> adj[N];
void dijkstra(ll s)
{
    priority_queue<node> pq;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e9;
        vis[i] = 0;
    }
    dis[s] = 0;
    pq.push({s, dis[s]});
    cnt[s] = 1;
    while (!pq.empty())
    {
        node cur = pq.top();
        pq.pop();
        ll u = cur.v;
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto x : adj[u])
        {
            ll v = x.v, w = x.w;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                //cout << "update:" << u << "to" << v << ".cnt[" << v << "] change into" << cnt[u] << "\n";
                cnt[v] = cnt[u];
                pq.push({v, dis[v]});
            }
            else if (dis[u] + w == dis[v])
            {
                cnt[v] += cnt[u];
                //cout << "update1:" << u << "to" << v << ".cnt[" << v << "] from " << cnt[v]-cnt[u] << "change into" << cnt[v] << "\n";
            }
        }
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
            adj[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                if (x[j]-x[i] <= d)
                {
                    adj[i].push_back({j, 1});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            dijkstra(i);
            for (int j = 1; j <= n; j++)
            {
                //cout << i << " " << j << " " << cnt[j] << "\n";
                if (j == i) continue;
                if (cnt[j] == 2) ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
