#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10;
vector<int> g[N + 5];
bool vis[N + 5];
int n, k;
int f[N + 5];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy)
        f[fx] = fy;
}
inline void init() {
    for (int i = 1; i <= n; i ++)
        f[i] = i;
}
int dis[N + 5][N + 5];
void bfs() {
    memset(dis, 0xff, sizeof dis);
    queue<int> q;
    for (int i = 1; i <= n; i ++) {
        dis[i][i] = 0;
        q.push(i);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int nxt : g[t])
                if (dis[i][nxt] == -1)
                    dis[i][nxt] = dis[i][t] + 1, q.push(nxt);
        }
    }
}
int d[N + 5], ans;
void dfs(int id, int cnt) {
    if (id > n) {
        if (cnt != k) return ;
        init();
        for (int i = 1; i <= n; i ++)
            if (vis[i])
                for (int j : g[i])
                    if (vis[j])
                        merge(i, j);
        map<int, int> mp;
        for (int i = 1; i <= n; i ++)
            mp[find(i)] ++;
        if (mp.size() > 2)
            return ;
        for (int i = 1; i <= n; i ++)
            if (!vis[i]) {
                d[i] = 9e18;
                for (int j = 1; j <= n; j ++)
                    if (vis[j])
                        d[i] = min(d[i], dis[i][j]);
            }
            else d[i] = 0;
        ans = min(ans, *max_element(d + 1, d + n + 1));
        return ;
    }
    vis[id] = 0;
    dfs(id + 1, cnt);
    if (cnt < k) {
        vis[id] = 1;
        dfs(id + 1, cnt + 1);
    }
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int cs, T;
    cin >> cs >> T;
    while (T --) {
        cin >> n >> k;
        for (int i = 1; i < n; i ++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bfs();
        ans = 9e18;
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}