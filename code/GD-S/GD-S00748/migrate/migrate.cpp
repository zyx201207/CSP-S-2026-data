#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
const int M = 5e3 + 10;
const int I = 1e9;
queue<int> q;
vector<int> adj[M];
int c, T, n, dis[N], cnt[N];
long long d, x[N];

void clear() {
    for (int i = 1; i <= n; i++) adj[i].clear();
}

void bfs(int s) {
    for (int i = 1; i <= n; i++) dis[i] = I;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    dis[s] = 0, cnt[s] = 1, q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (dis[u] + 1 == dis[v]) cnt[v] += cnt[u];
            else if (dis[u] + 1 < dis[v]) cnt[v] = cnt[u], dis[v] = dis[u] + 1, q.push(v);
        }
    }
}

void solve() {
    clear();
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (abs(x[i] - x[j]) <= d) adj[i].push_back(j);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        bfs(i);
        for (int j = i + 1; j <= n; j++) if (cnt[j] == 2) ans++;
    }
    cout << ans << "\n";
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> T;
    while (T--) solve();
    return 0;
}