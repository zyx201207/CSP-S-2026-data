#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 105;
int c, t, n, k;
vector<int> g[N];
bool vis[N];
int d[N];
int bfs(int x) {
    memset(d, -1, sizeof(d));
    d[x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int y = q.front(); q.pop();
        if(vis[y]) return d[y];
        for(int u : g[y])
            if(d[u] == -1){
                d[u] = d[y] + 1;
                q.push(u);
            }
    }
    return 1e18;
}
int dfs(int x, int y, int step) {
    if(step == 0) {
        int ans = 0;
        for(int i = 1; i <= n; i++) ans = max(ans, bfs(i));
        return ans;
    }
    int ans = 1e18;
    for(int u : g[x])
        if(!vis[u]) {
            vis[u] = 1;
            ans = min(ans, dfs(u, y, step - 1));
            vis[u] = 0;
        }
    for(int u : g[y])
        if(!vis[u]) {
            vis[u] = 1;
            ans = min(ans, dfs(x, u, step - 1));
            vis[u] = 0;
        }
    return ans;
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%lld %lld", &c, &t);
    while(t--) {
        int ans = 1e18;
        scanf("%lld %lld", &n, &k);
        for(int i = 1; i < n; i++) {
            int u, v; scanf("%lld %lld", &u, &v);
            g[u].push_back(v); g[v].push_back(u);
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                memset(vis, 0, sizeof(vis));
                vis[i] = 1; vis[j] = 1;
                ans = min(ans, dfs(i, j, k - 2));
            }
        printf("%lld\n", ans);
        for(int i = 1; i <= n; i++) g[i].clear();
    }
}

