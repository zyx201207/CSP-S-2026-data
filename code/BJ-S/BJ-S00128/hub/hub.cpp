#include <bits/stdc++.h>
using namespace std;

int C, T;
int n, k, ans;
vector <int> g[1000005];
bool vis[1000005];
int dis[1000005], dep[1000005], fa[1000005][21];

void dfs (int u, int f, int mask) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (v == f) {
            continue;
        }
        if ((1 << (v - 1)) & mask) {
            dfs(v, u, mask);
        }
    }
}

void mark (int u, int f) {
    dis[u] = dis[f] + 1;
    for (int v : g[u]) {
        if (v == f) {
            continue;
        }
        if (dis[v] <= dis[u] + 1) {
            continue;
        }
        dis[v] = dis[u] + 1;
        mark(v, u);
    }
}

void dfs2 (int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int v : g[u]) {
        if (v == f) {
            continue;
        }
        dfs2(v, u);
    }
}

void dfs3 (int u, int f, int step, int x) {
    if (step <= x) {
        vis[u] = 1;
    } else {
        return;
    }
    for (int v : g[u]) {
        if (v == f) {
            continue;
        }
        dfs3(v, u, step + 1, x);
    }
}

bool check (int x) {
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }
    dfs2(1, 0);
    int maxn = 0;
    for (int i = 1; i <= n; ++i) {
        if (dep[i] > dep[maxn]) {
            maxn = i;
        }
    }
    int pos = maxn;
    for (int k = 20; k >= 0; --k) {
        if (dep[maxn] - dep[fa[pos][k]] <= x && fa[pos][k] != 0) {
            pos = fa[pos][k];
        }
    }
    dfs3(pos, 0, 0, x);
    maxn = 1;
    for (int i = 1; i <= n; ++i) {
        if (dep[i] > dep[maxn] && !vis[i]) {
            maxn = i;
        }
    }
    pos = maxn;
    for (int k = 20; k >= 0; --k) {
        if (dep[maxn] - dep[fa[pos][k]] <= x && fa[pos][k] != 0) {
            pos = fa[pos][k];
        }
    }
    dfs3(pos, 0, 0, x);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            return 0;
        }
    }
    return 1;
}

void solve () {
    cin >> n >> k;
    ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        vis[i] = 0;
        fa[i][0] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (k != 2) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int i = 1; i <= n; ++i) {
                dis[i] = 0x3f3f3f3f;
                vis[i] = 0;
            }
            int num = 0;
            for (int i = 1; i <= n; ++i) {
                if ((1 << (i - 1)) & mask) {
                    num++;
                }
            }
            if (num > k) {
                continue;
            }
            for (int i = 1; i <= n; ++i) {
                vis[i] = 0;
            }
            int cnt = 0;
            for (int i = 1; i <= n; ++i) {
                if (!vis[i]) {
                    if ((1 << (i - 1)) & mask && cnt < 2) {
                        dfs(i, 0, mask);
                        cnt++;
                    }
                }
            }
            bool b = 1;
            for (int i = 1; i <= n; ++i) {
                if ((1 << (i - 1)) & mask) {
                    if (!vis[i]) {
                        b = 0;
                        break;
                    }
                }
            }
            if (!b) {
                continue;
            }
            for (int i = 1; i <= n; ++i) {
                if ((1 << (i - 1)) & mask) {
                    dis[0] = -1;
                    mark(i, 0);
                }
            }
            int res = 0;
            for (int i = 1; i <= n; ++i) {
                res = max(res, dis[i]);
            }
            ans = min(ans, res);
        }
    } else {
        dfs2(1, 0);
        for (int j = 1; j <= 20; ++j) {
            for (int i = 1; i <= n; ++i) {
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
            }
        }
        int l = 0, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    cout << ans << "\n";
}

int main () {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> C >> T;
    while (T--) {
        solve();
    }
    return 0;
}
