// 贵阳市第一中学 林钰涵 GZ-S00198
#include <bits/stdc++.h>
using namespace std;

int testid, n, m, maxd, Q, etot, a[500005], head[505], val[505];
long long d[505][505];
vector<pair<int, int> > ver[505];
vector<pair<int, int> > edges[500005];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int> > > q;
struct E {
    int to, w, nxt;
} e[500005];

void addedge(int u, int v, int w) {
    e[etot] = {v, w, head[u]}, head[u] = etot++;
}

void dij(int s, long long d[]) {
    for (int i = 1; i <= m; i++) {
        d[i] = 0x3f3f3f3f3f3f3f3f;
    }
    d[s] = 0;
    q.emplace(d[s], s);
    while (!q.empty()) {
        long long dis = q.top().first;
        int u = q.top().second;
        q.pop();
        if (dis > d[u]) continue;
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to, w = e[i].w;
            if (d[v] > dis + w) {
                d[v] = dis + w;
                q.emplace(d[v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> testid >> m >> n >> maxd >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        head[i] = -1;
    }
    for (int i = 1, k, v, w; i <= m; i++) {
        cin >> k;
        while (k--) {
            cin >> v >> w;
            ver[i].emplace_back(v, w);
            edges[v].emplace_back(i, w);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            val[j] = 0x7f7f7f7f;
        }
        for (auto& ve : ver[i]) {
            int x = ve.first, w = ve.second;
            for (auto& ed : edges[x]) {
                int u = ed.first, ww = ed.second;
                val[u] = min(val[u], ww + w);
            }
        }
        for (int j = 1; j <= m; j++) {
            if (val[j] < 0x7f7f7f7f) addedge(i, j, val[j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        dij(i, d[i]);
    }
    for (int i = 1, u, v; i <= Q; i++) {
        cin >> u >> v;
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for (auto& ed : edges[u]) {
            for (auto& ed2 : edges[v]) {
                ans = min(ans, d[ed.first][ed2.first] + ed.second + ed2.second);
            }
        }
        cout << ans + a[u] + a[v] << '\n';
    }
    return 0;
}
