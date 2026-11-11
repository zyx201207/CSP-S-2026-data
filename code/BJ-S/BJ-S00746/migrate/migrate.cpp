#include<iostream>
#define int long long

const int N = 9;
int c, t, n, d, x[N], ans, tt, mn;

int dfs(int i, int j, int step) {
    if (i == j) {
        if (step == mn) tt ++;
        else if (step < mn) {
            mn = step, tt = 1;
        }
        return 0;
    }
    for (int ti = i + 1; ti <= j; ti ++) {
        if (x[ti] - x[i] <= d) dfs(ti, j, step + 1);
        else break;
    }
}
void solve() {
    std::cin >> n >> d;
    ans = 0;
    for (int i = 1; i <= n; i ++) std::cin >> x[i];
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 3; j <= n; j ++) {
            tt = 0, mn = (j - i + 1);
            dfs(i, j, 0);
            if (tt == 2) ans ++;
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    std::cin >> c >> t;
    while (t --) solve();
    return 0;
}
