#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
const int INF = 1e8;
int n, k, c, t, a[MAXN];
vector<int> tree[MAXN];

namespace Brute {
    const int N = 1005;
    int dp[N][N][3][2], siz[N], tmp[N][3][2];

    bool checkBrute() { return c <= 8; }

    void dfs(int u, int fa, int mx) {
        for (int i = 0; i <= n; ++i) {
            for (int num = 0; num <= 2; ++num) {
                for (int is = 0; is <= 1; ++is) {
                    dp[u][i][num][is] = -INF;
                }
            }
        }
        dp[u][0][0][0] = -1, siz[u] = 1;
        dp[u][1][1][1] = mx;
        for (int v : tree[u]) {
            if (v == fa) continue;
            dfs(v, u, mx);
            for (int i = 0; i <= siz[u]; ++i) {
                for (int num = 0; num <= 2; ++num) {
                    for (int is = 0; is <= 1; ++is) {
                        tmp[i][num][is] = dp[u][i][num][is];
                        dp[u][i][num][is] = -INF;
                    }
                }
            }
            for (int i = 0; i <= siz[u]; ++i) {
                for (int num = 0; num <= 2; ++num) {
                    for (int is = 0; is <= 1; ++is) {
                        int lim = min(siz[v], k - i);
                        if (tmp[i][num][is] == -INF) continue;
                        for (int j = 0; j <= lim; ++j) {
                            for (int num2 = 0; num2 <= 2; ++num2) {
                                for (int is2 = 0; is2 <= 1; ++is2) {
                                    if (dp[v][j][num2][is2] == -INF) continue;
                                    int x = tmp[i][num][is] + 1, y = dp[v][j][num2][is2];
                                    int new_num = num + num2 - (is && is2);
                                    if (new_num > 2) continue;
                                    if (x > y) swap(x, y);
                                    // if (i == 0 && j == 0) cout << "qwq " << x << ' ' << y << ' ' << num2 << ' ' << is2 << '\n';
                                    // x <= y
                                    if (x <= 0 && y <= 0) {
                                        dp[u][i + j][new_num][is] = max(dp[u][i + j][new_num][is], x - 1);
                                    } else if (x <= 0) {
                                        if (abs(y) > abs(x)) {
                                            dp[u][i + j][new_num][is] = max(dp[u][i + j][new_num][is], y - 1);
                                        } else {
                                            dp[u][i + j][new_num][is] = max(dp[u][i + j][new_num][is], x - 1);
                                        }
                                    } else {
                                        dp[u][i + j][new_num][is] = max(dp[u][i + j][new_num][is], y - 1);
                                    }
                                    if (is && dp[u][i + j][new_num][is] < -mx) {
                                        dp[u][i + j][new_num][is] = -INF;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            siz[u] += siz[v];
            siz[u] = min(siz[u], k);
        }
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= 2; ++j) {
                if (dp[u][i][j][1] >= -mx) dp[u][i][j][1] = mx;
            }
        }
        // cout << u << ":\n";
        // for (int i = 0; i <= k; ++i) {
        //     for (int j = 0; j <= 2; ++j) {
        //         for (int k = 0; k <= 1; ++k) {
        //             if (dp[u][i][j][k] != -INF) {
        //                 cout << u << ' ' << i << ' ' << j << ' ' << k << ' ' << dp[u][i][j][k] << '\n';
        //             }
        //         }
        //     }
        // }
    }

    bool check(int mid) {
        dfs(1, 0, mid);
        int res = -INF;
        for (int num = 0; num <= 2; ++num) {
            for (int is = 0; is <= 1; ++is) {
                res = max(res, dp[1][k][num][is]);
            }
        }
        // cout << mid << ' ' << res << '\n';
        if (res >= 0) return true;
        else return false;
    }

    void solveBrute() {
        int L = 0, R = n - k, res = n;
        while (L <= R) {
            int mid = L + R >> 1;
            if (check(mid)) {
                R = mid - 1;
                res = mid;
            } else {
                L = mid + 1;
            }
        }
        cout << res << '\n';
    }
}


namespace SubC {
    const int N = 5e5 + 5;
    int dp[N][10][3][2], siz[N], tmp[10][3][2];

    bool checkSubC() { return k <= 10; }

    void dfs(int u, int fa, int mx) {
        for (int i = 0; i <= k; ++i) {
            for (int num = 0; num <= 2; ++num) {
                for (int is = 0; is <= 1; ++is) {
                    dp[u][i][num][is] = -INF;
                }
            }
        }
        dp[u][0][0][0] = -1, siz[u] = 1;
        dp[u][1][1][1] = mx;
        for (int v : tree[u]) {
            if (v == fa) continue;
            dfs(v, u, mx);
            for (int i = 0; i <= siz[u]; ++i) {
                for (int num = 0; num <= 2; ++num) {
                    for (int is = 0; is <= 1; ++is) {
                        tmp[i][num][is] = dp[u][i][num][is];
                        dp[u][i][num][is] = -INF;
                    }
                }
            }
            for (int i = 0; i <= siz[u]; ++i) {
                for (int num = 0; num <= 2; ++num) {
                    for (int is = 0; is <= 1; ++is) {
                        int lim = min(siz[v], k - i);
                        if (tmp[i][num][is] == -INF) continue;
                        for (int j = 0; j <= lim; ++j) {
                            for (int num2 = 0; num2 <= 2; ++num2) {
                                for (int is2 = 0; is2 <= 1; ++is2) {
                                    if (dp[v][j][num2][is2] == -INF) continue;
                                    int x = tmp[i][num][is] + 1, y = dp[v][j][num2][is2];
                                    int new_num = num + num2 - (is && is2);
                                    if (new_num > 2) continue;
                                    if (x > y) swap(x, y);
                                    // if (i == 0 && j == 0) cout << "qwq " << x << ' ' << y << ' ' << num2 << ' ' << is2 << '\n';
                                    // x <= y
                                    if (x <= 0 && y <= 0) {
                                        dp[u][i + j][new_num][is] = max(dp[u][i + j][new_num][is], x - 1);
                                    } else if (x <= 0) {
                                        if (abs(y) > abs(x)) {
                                            dp[u][i + j][new_num][is] = max(dp[u][i + j][new_num][is], y - 1);
                                        } else {
                                            dp[u][i + j][new_num][is] = max(dp[u][i + j][new_num][is], x - 1);
                                        }
                                    } else {
                                        dp[u][i + j][new_num][is] = max(dp[u][i + j][new_num][is], y - 1);
                                    }
                                    if (is && dp[u][i + j][new_num][is] < -mx) {
                                        dp[u][i + j][new_num][is] = -INF;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            siz[u] += siz[v];
            siz[u] = min(siz[u], k);
        }
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= 2; ++j) {
                if (dp[u][i][j][1] >= -mx) dp[u][i][j][1] = mx;
            }
        }
        // cout << u << ":\n";
        // for (int i = 0; i <= k; ++i) {
        //     for (int j = 0; j <= 2; ++j) {
        //         for (int k = 0; k <= 1; ++k) {
        //             if (dp[u][i][j][k] != -INF) {
        //                 cout << u << ' ' << i << ' ' << j << ' ' << k << ' ' << dp[u][i][j][k] << '\n';
        //             }
        //         }
        //     }
        // }
    }

    bool check(int mid) {
        dfs(1, 0, mid);
        int res = -INF;
        for (int num = 0; num <= 2; ++num) {
            for (int is = 0; is <= 1; ++is) {
                res = max(res, dp[1][k][num][is]);
            }
        }
        // cout << mid << ' ' << res << '\n';
        if (res >= 0) return true;
        else return false;
    }

    void solveSubC() {
        int L = 0, R = n - k, res = n;
        while (L <= R) {
            int mid = L + R >> 1;
            if (check(mid)) {
                R = mid - 1;
                res = mid;
            } else {
                L = mid + 1;
            }
        }
        cout << res << '\n';
    }
}

void clear() {
    for (int i = 1; i <= n; ++i) tree[i].clear();
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    if (Brute::checkBrute()) {
        Brute::solveBrute();
        clear();
        return;
    } else if (SubC::checkSubC()) {
        SubC::solveSubC();
        clear();
        return;
    }

    clear();
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> t;
    while (t--) solve();
}

/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9 
9 10
*/