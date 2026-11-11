#include <bits/stdc++.h>
#define N 501000
#define fi first
#define se second
#define vt vector
#define it(a, n) a.begin() + 1, a.begin() + (n) + 1
#define INF 1e15
#define int long long
#define pii pair <int, int>
#define rep(i, s, t) for (int i = (s); i <= (t); i += 1)
using namespace std;
namespace G{
    array <vt <pii>, N> edge;
    void add(int u, int v, int w) {
        edge[u].push_back({v, w});
    }
}
int c, n, m, d, q;
array <int, N> w;
void dij(int s, vt <int> &d) {
    priority_queue <pii> pq;
    pq.push({-(d[s] = 0), s});
    while (!pq.empty()) {
        int dis = -pq.top().fi, u = pq.top().se;
        pq.pop();
        if (dis != d[u])
            continue;
        for (pii x : G::edge[u]) {
            int v = x.fi, tmp = dis + x.se;
            if (tmp < d[v])
                pq.push({-(d[v] = tmp), v});
        }
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    rep(i, 1, m)
        cin >> w[i];
    rep(u, m + 1, m + n) {
        int k;
        cin >> k;
        rep(_, 1, k) {
            int v, w;
            cin >> v >> w;
            G::add(u, v, w);
            G::add(v, u, w);
        }
    }
    if (c <= 11) {
        vt <vt <int>> d(m + 1, vt <int> (n + m + 1, INF));
        rep(i, 1, m)
            dij(i, d[i]);
        while (q --) {
            int u, v;
            cin >> u >> v;
            cout << w[u] + d[u][v] + w[v] << "\n";
        }
        return 0;
    }
    if (c <= 15) {
        while (q --) {
            int u, v, T = G::edge[1][0].se;
            cin >> u >> v;
            vt <int> d(m + n + 1, INF);
            queue <int> q;
            q.push(u);
            d[u] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (pii x : G::edge[u]) {
                    int v = x.fi;
                    if (d[u] + 1 < d[v]) {
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                }
            }
            cout << w[u] + d[v] * T + w[v] << "\n";
        }
        return 0;
    }
    if (20 <= c && c <= 21) {
        if (n == 1) {
            while (q --) {
                int u, v;
                cin >> u >> v;
                cout << w[u] + G::edge[u][0].se + G::edge[v][0].fi + w[v] << "\n";
            }
            return 0;
        }
        vt <int> w1(m + 1, INF), w2(m + 1, INF);
        for (pii x : G::edge[m + 1])
            w1[x.fi] = x.se;
        for (pii x : G::edge[m + 2])
            w2[x.fi] = x.se;
        int D12 = INF;
        rep(i, 1, m)
            D12 = min(D12, w1[i] + w2[i]);
        while (q --) {
            int u, v;
            cin >> u >> v;
            int ans1 = w1[u] + w1[v], ans2 = w2[u] + w2[v],
                ans12 = w1[u] + D12 + w2[v], ans21 = w2[u] + D12 + w1[v];
            cout << w[u] + min({ans1, ans2, ans12, ans21}) + w[v] << "\n";
        }
        return 0;
    }
    return 0;
}