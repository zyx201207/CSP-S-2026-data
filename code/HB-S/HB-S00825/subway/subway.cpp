#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int M = 500505, N = 505;
constexpr ll Inf = 1000000000000000000ll;

int c, n, m, d, q;
ll w[M], dis[N][M], T;
struct edge {
    int v;
    ll W;
};
struct node {
    int id;
    ll d;
    inline bool operator < (const node &nd) const {
        return (d > nd.d);
    }
};
vector <node> to[M];
vector <edge> G[M];

inline void dijkstra(int ri, int i) {
    dis[ri][i] = 0ll;
    priority_queue <node> pq;
    pq.push((node){i, 0ll});
    while (!pq.empty()) {
        int u = pq.top().id;
        ll d = pq.top().d;
        pq.pop();
        if (d > dis[ri][u]) continue;
        for (const edge &e : G[u]) {
            int v = e.v;
            ll W = e.W;
            if (dis[ri][v] > d + W) dis[ri][v] = d + W, pq.push((node){v, dis[ri][v]});
        }
    }
    return void();
}

int ds[M];

void sp() {
    for (int i = m + 1, ri = 1; i <= m + n; ++i, ++ri) {
        queue <int> q;
        q.push(i);
        memset(ds, 0, sizeof ds);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const edge &e : G[u]) if (e.v != i && !ds[e.v]) {
                int v = e.v;
                ds[e.v] = ds[u] + 1, q.push(v);
            }
        }
        for (int j = 1; j <= n + m; ++j) dis[ri][j] = T * ds[j];
    }
    return void();
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin.tie(0), cout.tie(0);

    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = m + 1, k, id; i <= m + n; ++i) {
        cin >> k;
        ll cost;
        while (k--) {
            cin >> id >> cost, T = cost;
            to[id].push_back((node){i, cost}), G[id].push_back((edge){i, cost}), G[i].push_back((edge){id, cost});
        }
    }

    if (16 <= c && c <= 19) sp();
    else {
        for (int i = m + 1; i <= m + n; ++i) {
            int ri = i - m;
            memset(dis[ri], 0x3f, sizeof dis[ri]);
            dijkstra(ri, i);
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        ll ans = Inf;
        for (const node &e : to[x]) {
            int S = e.id;
            ll cost = e.d, res;
            res = w[x] + w[y] + dis[S - m][y] + cost;
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }

    return 0;
}