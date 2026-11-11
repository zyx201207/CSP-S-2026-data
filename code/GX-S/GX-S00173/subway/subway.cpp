#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 510, M = 5e5 + 10;
struct node {
    LL dist;
    int lineId, u;
    bool operator < (const node &oth) const {
        return dist > oth.dist;
    }
};
int c, n, m, d, q;
LL w[M];
set<int> has[N];
vector<vector<int>> vis, times;
vector<vector<LL>> dis;
vector<pair<int, int>> line[N];
priority_queue<node> Q;
void in(LL dist, int lineId, int u) {
    Q.push(node{dist, lineId, u});
}
void solve(int xr, int yr) {
    LL ans = 1e18;
    while (Q.size())
        Q.pop();
    dis.assign(n + 1, vector<LL>(m + 1, 1e18));
    vis.assign(n + 1, vector<int>(m + 1, 0));
    //Q.push(node{1, 0, 0});
    //Q.push(node{2, 0, 0});
    //cout << Q.top().dist;
    //cout << dis[1][1];
    for (int id = 1; id <= n; id++)
        if (has[id].find(xr) != has[id].end())
            in(times[id][xr], id, xr), dis[id][xr] = times[id][xr];

    while (Q.size()) {
        node cur = Q.top();
        Q.pop();
        LL dist = cur.dist;
        int id = cur.lineId, u = cur.u;
        if (u == yr) {
            ans = min(ans, dist + times[id][u]);
            break;
        }
        if (vis[id][u])
            continue;
        vis[id][u] = 1;
        //cout << dist << ' ' << id << ' ' << u << '\n';
        // in the same lines
        for (auto pii : line[id]) {
            int v = pii.first;
            if (dis[id][v] > dis[id][u]) {
                dis[id][v] = dis[id][u];
                in(dis[id][v], id, v);
            }
        }
        // transform
        for (int nxt = 1; nxt <= n; nxt++) {
            if (nxt == id || has[nxt].find(u) == has[nxt].end())
                continue;
            if (dis[nxt][u] > dis[id][u] + times[id][u] + times[nxt][u]) {
                dis[nxt][u] = dis[id][u] + times[id][u] + times[nxt][u];
                in(dis[nxt][u], nxt, u);
            }
        }
    }

    cout << ans + w[xr] + w[yr] << '\n';
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> c >> n >> m >> d >> q;
    times.resize(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        for (int j = 1, a, t; j <= k; j++) {
            cin >> a >> t;
            line[i].push_back({a, t});
            has[i].insert(a);
            times[i][a] = t;
        }
    }
    for (int i = 1, xr, yr; i <= q; i++) {
        cin >> xr >> yr;
        //cout << "Round " << i << ":\n";
        solve(xr, yr);
        //cout << '\n';
    }
    return 0;
}
