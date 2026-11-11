#include <bits/stdc++.h>
#define MAXN 505
using namespace std;
typedef long long ll;
typedef pair<ll, int> pir;
ll dis[MAXN][MAXN], w[MAXN];
vector<pair<int, ll>> G[500000 + MAXN];
priority_queue<pir, vector<pir>, greater<pir>> que; //{value,node}
long long vis[500000 + MAXN];
template <typename T>
inline void read(T &x)
{
    x = 0;
    char c = getchar();
    while (c < '0' || '9' < c)
        c = getchar();
    while ('0' <= c && c <= '9')
    {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, n, m, d, q;
    read(c), read(n), read(m), read(d), read(q);
    for (int i = 1; i <= m; i++)
        read(w[i]);
    for (int i = 1; i <= n; i++)
    {
        int k;
        read(k);
        for (int j = 1; j <= k; j++)
        {
            int a;
            ll t;
            read(a), read(t);
            G[m + i].push_back({a, t});
            G[a].push_back({m + i, t});
        }
    }
    while (q--)
    {
        while (que.size())
            que.pop();
        memset(vis, 0x3f, sizeof(vis));
        int x, y;
        read(x), read(y);
        que.push({0, x});
        while (!que.empty())
        {
            ll val = que.top().first;
            int idx = que.top().second;
            if (idx == y)
            {
                cout << val + w[x] + w[y] << '\n';
                break;
            }
            que.pop();
            if (vis[idx] < val)
                continue;
            vis[idx] = val;
            for (auto &e : G[idx])
                if (val + e.second < vis[e.first])
                {
                    vis[e.first] = val + e.second;
                    que.push({val + e.second, e.first});
                }
        }
    }
    return 0;
}