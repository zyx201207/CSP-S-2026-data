#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const ll M = 5e5 + 5, N = 505;
int c;
int n, m, d, q;
ll w[M];
bool vis[N];
ll dis[N][N];
vector<pii> t[M];
vector<ll> ed[N];
vector<pii> e[N];

ll read()
{
    ll res = 0;

    char ch;
    ch = getchar();

    while (ch >= '0' && ch <= '9')
        res = res * 10 + ch - '0', ch = getchar();

    return res;
}

void dij(ll x)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    memset(vis, 0, sizeof vis);
    memset(dis[x], 0x3f, sizeof dis[x]);

    pq.push({0, x}), dis[x][x] = 0;

    while (!pq.empty())
    {
        pii tp = pq.top();
        pq.pop();

        ll u = tp.second, val = tp.first;

        if (vis[u])
            continue;
        vis[u] = 1;

        for (pii y : e[u])
        {
            ll v = y.first, we = y.second;

            if (vis[v])
                continue;

            if (dis[x][u] + we < dis[x][v])
                dis[x][v] = dis[x][u] + we, pq.push({dis[x][v], v});
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    c = read(), n = read(), m = read(), d = read(), q = read();

    for (ll i = 1; i <= m; ++i)
        w[i] = read();

    for (ll i = 1, k, u; i <= n; ++i)
    {
        k = read();
        for (ll j = 1; j <= k; ++j)
        {
            ll v;
            ll val;
            v = read(), val = read();

            ed[i].push_back(v);
            t[v].push_back({i, val});
        }
    }

    for (ll i = 1; i <= n; ++i)
        for (ll u : ed[i])
        {
            ll val1 = 0;
            for (pii x : t[u])
                if (x.first == i)
                {
                    val1 = x.second;
                    break;
                }

            for (pii x : t[u])
            {
                ll v = x.first, val = x.second;

                if (v == i)
                    continue;

                e[i].push_back({v, val + val1});
            }
        }

    for (ll i = 1; i <= n; ++i)
        dij(i);

    while (q--)
    {
        ll x, y;
        ll res = LLONG_MAX;
        ll p = 0;

        x = read(), y = read();

        for (pii u : t[x])
            for (pii v : t[y])
            {
                if (res > dis[u.first][v.first])
                    p = u.second + v.second, res = dis[u.first][v.first];
            }

        printf("%lld\n", w[x] + res + w[y] + p);
    }

    return 0;
}