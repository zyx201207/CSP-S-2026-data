#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c, t, n, k, u, v;
int head[N], tot, a[N], l, cnt, f[N];
bool vis[N];
struct node {
    int nxt, to;
}e[N];
void add(int x, int y) {
    e[++tot] = {head[x], y};
    head[x] = tot;
}
int pp;
vector<int> g[N], p[N];
void dfs(int x) {
    if(x > k) {
        cnt++;
        for(int i = 1; i <= k; i++) g[cnt].push_back(a[i]);
        return ;
    }
    for(int i = a[x - 1] + 1; i <= n; i++) {
        if(vis[i] == 0) {
            vis[i] = 1;
            a[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}
int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
int dep[N], fa[N][25];
void dfs_d(int x, int fat) {
    dep[x] = dep[fat] + 1;
    fa[x][0] = fat;
    for(int i = 1; i <= 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for(int i = head[x]; ~i; i = e[i].nxt) if(e[i].to != fat) dfs_d(e[i].to, x);
}
int lca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 20; ~i; i--) {
        if(dep[fa[x][i]] >= dep[y]) 
            x = fa[x][i];
    }
    if(x == y) return x;
    for(int i = 20; ~i; i--) {
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
void sol() { 
    cin >> n >> k;
    memset(head, -1, sizeof head);
    tot = -1;
    map<pair<int, int>, bool> mp;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        add(u, v), add(v, u);
        mp[{u, v}] = mp[{v, u}] = 1;
    }
    memset(vis, 0, sizeof vis);
    cnt = 0;
    dfs(1);
    pp = 0;
    for(int i = 1; i <= cnt; i++) {
        for(int j = 1; j <= n; j++) f[j] = j;
        for(int j = 0; j < g[i].size(); j++) {
            int u = g[i][j];
            for(int k = j + 1; k < g[i].size(); k++) {
                int v = g[i][k];
                int fu = find(u), fv = find(v);
                if(fu != fv) f[fu] = fv;
            }
        }
        int res = 0;
        for(int j : g[i]) res += (find(j) == j);
        if(res <= 2) {
            pp++;
            for(int j : g[i]) p[pp].push_back(j);
        }
    }
    dep[0] = 0;
    dfs_d(1, 0);
    int ans = 1e9;
    for(int i = 1; i <= pp; i++) {
        int mx = 0;
        for(int j = 0; j < p[i].size(); j++) {
            int u = p[i][j];
            for(int k = j + 1; k < p[i].size(); k++) {
                int v = p[i][k];
                mx = max(mx, dep[u] + dep[v] - 2 * dep[lca(u, v)]);
            }
        }
        ans = min(ans, mx);
    }
    cout << ans << endl;
}
int main() {
	ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--) sol();
	return 0;
} 