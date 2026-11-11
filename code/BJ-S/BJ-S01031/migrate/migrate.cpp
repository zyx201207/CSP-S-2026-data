#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, t, a[1000010];

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> t;
    while (t--) {
        int n, d, x, y;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (d >= (a[2] - a[1]) * 2) {
            cout << n - 3 << '\n';
        }
    }
    return 0;
}
