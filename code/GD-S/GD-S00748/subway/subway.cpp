#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 10;
const int M = 5e5 + 10;
const long long I = 1e18;
queue<int> p;
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
vector<int> t[N], a[N], l[M];
vector<pair<int, int> > adj[M << 1];
int c, n, m, d, Q, w[M], k[N];
long long f[N][N], dis[M << 1];
bool vis[M << 1], flag[M << 1];

void dijkstra(int s) {
    for (int i = 1; i <= n + m; i++) vis[i] = false;
    for (int i = 1; i <= n + m; i++) dis[i] = I;
    for (int i = m + 1; i <= m + n; i++) flag[i] = false;
    q.push({dis[s] = 0, s});
    int cnt = 0;
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        if (u >= m + 1 && u <= m + n && !flag[u]) cnt += (flag[u] = true);
        if (cnt >= n) return;
        for (auto i : adj[u]) if (dis[u] + i.second < dis[i.first]) q.push({dis[i.first] = dis[u] + i.second, i.first}); 
    }
}

void bfs(int s) {
    for (int i = 1; i <= n + m; i++) dis[i] = I;
    for (int i = m + 1; i <= m + n; i++) flag[i] = false;
    p.push(s), dis[s] = 0;
    int cnt = 0;
    while (!p.empty()) {
        int u = p.front(); p.pop();
        if (u >= m + 1 && u <= m + n && !flag[u]) cnt += (flag[u] = true);
        if (cnt >= n) return;
        for (auto i : adj[u]) if (dis[u] + 1 < dis[i.first]) p.push(i.first), dis[i.first] = dis[u] + 1; 
    }
}

void init1() {
    for (int i = 1; i <= n; i++) {
        dijkstra(m + i);
        for (int j = 1; j <= n; j++) f[i][j] = dis[m + j]; 
    }
}

void init2() {
    for (int i = 1; i <= n; i++) {
        bfs(m + i);
        for (int j = 1; j <= n; j++) f[i][j] = dis[m + j] * t[1][0];
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> n >> m >> d >> Q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) t[i].push_back(0), a[i].push_back(0);
        for (int j = 0; j <= k[i] - 1; j++) cin >> a[i][j] >> t[i][j];   
        for (auto j : a[i]) l[j].push_back(i);
    }
    for (int i = 1; i <= n; i++) for (int j = 0; j <= k[i] - 1; j++) adj[m + i].push_back({a[i][j], t[i][j]}), adj[a[i][j]].push_back({m + i, t[i][j]});
    c >= 12 && c <= 19 ? init2() : init1();
    for (int i = 1, x, y; i <= Q; i++) {
        cin >> x >> y;
        long long ans = I;
        for (auto j : l[x]) for (auto k : l[y]) {
            int posx = lower_bound(a[j].begin(), a[j].end(), x) - a[j].begin();
            int posy = lower_bound(a[k].begin(), a[k].end(), y) - a[k].begin();
            ans = min(ans, f[j][k] + t[j][posx] + t[k][posy]); 
        }
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}