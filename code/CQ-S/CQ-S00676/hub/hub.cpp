# include <bits/stdc++.h>

using namespace std;
const int N = 105;
const int INF = 1e9;
int n, k, sz[N], fa[N];
vector < int> G[N];
int dp[N][N][N][3][2], f[N][N][3];
inline void get_dp ( int cur_node, int fa_node, int vmid) {
    for ( int i = 0; i <= sz[cur_node]; i ++) {
        for ( int j = 0; j <= n; j ++) {
            for ( int k = 0; k < 3; k ++) {
                dp[cur_node][i][j][k][0] = dp[cur_node][i][j][k][1] = INF;
            }
        }
    }
    if ( sz[cur_node] == 1) {
        dp[cur_node][0][n][0][0] = 0;
        dp[cur_node][1][0][1][1] = - INF;
        return;
    }
    for ( auto & v : G[cur_node]) {
        if ( v != fa_node) {
            get_dp ( v, cur_node, vmid);
        }
    }
    // no choose
    int siz = 0;
    dp[cur_node][0][n][0][0] = 0;
    for ( auto & v : G[cur_node]) {
        if ( v == fa_node) {
            continue;
        }
        for ( int u = 0; u <= siz; u ++) {
            for ( int d = 0; d <= n; d ++) {
                for ( int blo = 0; blo < 3; blo ++) {
                    f[u][d][blo] = dp[cur_node][u][d][blo][0];
                    dp[cur_node][u][d][blo][0] = INF;
                }
            }
        }
        for ( int u = 0; u <= siz; u ++) {
            for ( int d = 0; d <= n; d ++) {
                for ( int blo = 0; blo < 3; blo ++) {
                    for ( int vu = 0; vu <= sz[v]; vu ++) {
                        for ( int vd = 0; vd <= n; vd ++) {
                            for ( int vblo = 0; vblo <= 2; vblo ++) {
                                for ( int vop = 0; vop < 2; vop ++) {
                                    if ( u + vu <= k && blo + vblo <= 2) {
                                        dp[cur_node][u + vu][min ( d, vd + 1)][blo + vblo][0] = min ( dp[cur_node][u + vu][min ( d, vd + 1)][blo + vblo][0], max ( f[u][d][blo], dp[v][vu][vd][vblo][vop] + 1));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        siz += sz[v];
    }
    // choose
    siz = 1;
    dp[cur_node][1][0][1][1] = - INF;
    for ( auto & v : G[cur_node]) {
        if ( v == fa_node) {
            continue;
        }
        for ( int u = 0; u <= siz; u ++) {
            for ( int d = 0; d <= n; d ++) {
                for ( int blo = 0; blo < 3; blo ++) {
                    f[u][d][blo] = dp[cur_node][u][d][blo][1];
                    dp[cur_node][u][d][blo][1] = INF;
                }
            }
        }
        for ( int u = 0; u <= siz; u ++) {
            for ( int d = 0; d <= n; d ++) {
                for ( int blo = 0; blo < 3; blo ++) {
                    for ( int vu = 0; vu <= sz[v]; vu ++) {
                        for ( int vd = 0; vd <= n; vd ++) {
                            for ( int vblo = 0; vblo <= 2; vblo ++) {
                                for ( int vop = 0; vop < 2; vop ++) {
                                    if ( u + vu <= k && blo + vblo - vop <= 2) {
                                        dp[cur_node][u + vu][min ( d, vd + 1)][blo + vblo - vop][1] = min ( dp[cur_node][u + vu][min ( d, vd + 1)][blo + vblo - vop][1], max ( f[u][d][blo], dp[v][vu][vd][vblo][vop] + 1));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        siz += sz[v];
    }
    for ( int u = 0; u <= siz; u ++) {
        for ( int d = 0; d <= n; d ++) {
            for ( int blo = 0; blo < 3; blo ++) {
                for ( int op = 0; op < 2; op ++) {
                    if ( dp[cur_node][u][d][blo][op] + d <= vmid) {
                        dp[cur_node][u][d][blo][op] = - INF;
                    }
                }
            }
        }
    }
}
inline bool check ( int v) {
    get_dp ( 1, 0, v);
    bool ok = 0;
    for ( int i = 0; i <= k; i ++) {
        for ( int j = 0; j <= n; j ++) {
            ok |= dp[1][i][j][1][0] < 0;
            ok |= dp[1][i][j][2][0] < 0;
            ok |= dp[1][i][j][1][1] < 0;
            ok |= dp[1][i][j][2][1] < 0;
        }
    }
    return ok;
}
inline void init_tree ( int cur_node, int fa_node) {
    sz[cur_node] = 1; fa[cur_node] = fa_node;
    for ( auto & v : G[cur_node]) {
        if ( v != fa_node) {
            init_tree ( v, cur_node);
            sz[cur_node] += sz[v];
        }
    }
}
inline void solve () {
    cin >> n >> k;
    for ( int i = 1; i <= n; i ++) {
        G[i].clear ();
    }
    for ( int i = 1; i < n; i ++) {
        int x, y; cin >> x >> y;
        G[x].push_back ( y);
        G[y].push_back ( x);
    }
    init_tree ( 1, 0);
    int l = 0, r = n + 1;
    while ( l + 1 < r) {
        int mid = l + r >> 1;
        if ( check ( mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}
signed main () {
    freopen ( "hub.in", "r", stdin); freopen ( "hub.out", "w", stdout);
    ios :: sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int c, T; cin >> c >> T;
    while ( T --) {
        solve ();
    }
}
