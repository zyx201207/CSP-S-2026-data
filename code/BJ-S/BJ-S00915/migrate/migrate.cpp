#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e6 + 10;

LL c, t, n, d, ans = 0, cnt = 1;
LL a[N], minstep = 1e9;

void dfs(int x, int y, long long sum) {
    if (x >= y) {
        if (sum == minstep) cnt++;
        if (sum < minstep) {
            minstep = sum;
            cnt = 1;
        }
        // cout << minstep << "\n";
        return ;
    }
    for (int i = x + 1; i <= n; i++) {
        if (a[i] - a[x] <= d) {
            dfs(i, y, sum + 1);
            --sum;
        }
    }
}

void solve() {
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            dfs(i, j, 0);
            if (cnt == 2) {
                ans++;
                // cout << a[i] << " " << a[j] << "\n";
            }
        }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cnt = 1, ans = 0;
        minstep = 1e9;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        solve();
        // dfs(1, 3, 0);
        cout << ans << "\n";
    }
    return 0;
}

