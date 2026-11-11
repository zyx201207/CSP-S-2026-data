#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 6e3 + 10;
int x[N];
int f[N][N];
int n, d, cnt;

void dfs(int l, int r, int step) {
    if (cnt >= 3) return;
    if (step > f[l][r]) return;
    if (l == r) {
        ++cnt;
        return;
    }
    for (int i = l; i <= r; ++i) {
        if (x[i] - x[l] <= d) dfs(i, r, step + 1);
        else return;
    }
}

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (x[j] - x[i] <= d) f[i][j] = 1;
            else break;
        }
    }
    int ans = 0;
    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l <= n - len + 1; ++l) {
            int r = l + len - 1;
            if (f[l][r] == 1) continue;
            for (int i = l + 1; i < r; ++i) {
                f[l][r] = min(f[l][r], f[l][i] + f[i][r]);
            }
            if (len <= 3) continue;
            cnt = 0;
            dfs(l, r, 0);
            if (cnt == 2) ++ans;
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        solve();
    }
    return 0;
}
