#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5, INF = INT_MAX;
ll c, n, m, d, Q, x, y, w[N], k, a, T;
vector <ll> Edges[N], Point[N];
ll dist[N];
queue <ll> q;
void Bfs(ll x, ll y) {
    q.push(x);
    dist[x] = 0;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        if (u == y) return ;
        for (const auto &vRoad : Point[u]) {
            for (const auto &vPoint : Edges[vRoad]) {
                if (dist[vPoint] == INF) {
                    dist[vPoint] = min(dist[vPoint], dist[u] + 1);
                    q.push(vPoint);
                }
            }
        }
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> Q;
    for (ll i = 1; i <= m; i++) cin >> w[i];
    for (ll i = 1; i <= n; i++) {
        cin >> k;
        for (ll j = 1; j = k; j++) {
            cin >> a >> T;
            Edges[k].push_back(a);
            Point[a].push_back(k);
        }
    }
    while (Q--) {
        cin >> x >> y;
        ll ans = 0;
        ans += w[x] + w[y];
        for (ll i = 1; i <= m; i++) dist[i] = INF;
        Bfs(x, y);
        ans += dist[y] * T;
    }
    return 0;
}

