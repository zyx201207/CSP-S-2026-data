#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e6 + 5;
int c, t, n;
long long d, p[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    for (int k = 1; k <= t; k++) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> p[i];
        if (n < 4 || d < 2) {
            cout << 0 << '\n';
            continue;
        }
        if (c == 11 || c == 12) {
            long long ans = 0, cell = p[2] - p[1];
            if (d < 2 * cell) {
                cout << 0 << '\n';
                continue;
            }
            d /= cell;
            for (int i = 1; i <= n; i++) p[i] /= cell;
            for (int l = 1, r = 1; r <= n; ) {
                if (r - l > 1 && p[r] - p[l] == 2 * d - 1) ans++;
                if (p[r] - p[l] <= 2 * d - 1) r++;
                else l++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
