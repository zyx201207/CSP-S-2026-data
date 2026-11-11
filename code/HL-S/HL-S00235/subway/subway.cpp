#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

using ll = long long;

constexpr static const int maxn = 5e5 + 1000, maxm = 2e7 + 5, maxq = 1e5 + 5;

int to[maxm], nxt[maxm], val[maxm], head[maxn], cnt;
void adde(int u, int v, int w) {
    to[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

ll dis[maxn];
bool vis[maxn];
priority_queue<pair<ll, int>> pq;
void Dijkstra(int s) {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[s] = 0;
    pq.emplace(0, s);
    while (pq.size()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = nxt[i]) if (dis[to[i]] > dis[u] + val[i]) {
            dis[to[i]] = dis[u] + val[i];
            pq.emplace(-dis[to[i]], to[i]);
        }
    }
}

int c, n, m, d, q, x, y, w[maxn], t;
ll ans[maxq];
vector<pair<int, int>> qs[maxn];

namespace spj_B {
    queue<pair<int, int>> q;
    int sl(int s) {
        memset(vis, 0, sizeof vis);
        vis[s] = 1;
        q.emplace(s, 0);
        dis[s] = 0;
        while (q.size()) {
            auto u = q.front();
            q.pop();
            for (int i = head[u.first]; i; i = nxt[i]) if (!vis[to[i]]) {
                q.emplace(to[i], dis[u.first] = u.second + 1);
                vis[to[i]] = true;
            }
        }
    }
    void main() {
        for (int i = 1; i <= m; i++) if (qs[i].size()) {
            sl(i);
            for (auto j : qs[i]) ans[j.second] = dis[j.first] * t + w[i] + w[j.first];
        }
        for (int i = 1; i <= ::q; i++) cout << ans[i] << '\n';
    }
};

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1, k, a; i <= n; i++) {
        cin >> k;
        while (k--) {
            cin >> a >> t;
            adde(m + i, a, t);
            adde(a, m + i, t);
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> x >> y;
        qs[x].emplace_back(y, i);
    }
    if (c >= 12 && c <= 19) {
        spj_B::main();
        return 0;
    }
    for (int i = 1; i <= m; i++) if (qs[i].size()) {
        Dijkstra(i);
        for (auto j : qs[i]) ans[j.second] = dis[j.first] + w[i] + w[j.first];
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}
