#include <bits/stdc++.h>
using namespace std;

int c, t, n, k;
vector<int> g[100005];
int ans, c1[100005], vis[100005];
int bfs[105][105];
queue<int> q;

void dfs1(int x) {
    if(vis[x] || !c1[x]) return;
    vis[x] = 1;
    for (int i = 0; i < g[x].size(); ++i) dfs1(g[x][i]);
}
void bfs1(int t, int x) {
    while(q.size()) q.pop();
    q.push(x);
    for (int i = 1; i <= n; ++i) bfs[t][i] = 1e9, vis[i] = 0;
    bfs[t][x] = 0;
    vis[x] = 1;
    while(q.size()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); ++i) {
            if(!vis[g[u][i]]) {
                vis[g[u][i]] = 1;
                bfs[t][g[u][i]] = bfs[t][u] + 1;
                q.push(g[u][i]);
            }
        }
    }
}

void dfs(int now, int cnt) {
    if(now > n) {
        if(cnt != k) return;
        int cur = 0;
        for (int i = 1; i <= n; ++i) vis[i] = 0;
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if(c1[i] && !vis[i]) {
                cur++;
                dfs1(i);
                if(cur > 2) {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag || cur > 2) {
            return;
        }
        cur = 0;
        for (int i = 1; i <= n; ++i) {
            if(c1[i]) bfs1(++cur, i);
        }
        int k1 = 0;
        for (int i = 1; i <= n; ++i) {
            int k2 = 1e9;
            for (int j = 1; j <= cur; ++j) k2 = min(k2, bfs[j][i]);
            k1 = max(k1, k2);
        }
  //      cout << k1 << "\n";
        ans = min(ans, k1);
        return;
    }
    if(cnt > k) return;
    c1[now] = 1;
    dfs(now + 1, cnt + 1);
    c1[now] = 0;
    dfs(now + 1, cnt);
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) g[i].clear(), c1[i] = 0;
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans = 1e9;
        dfs(1, 0);
        cout << ans << "\n";
    }
    return 0;
}
