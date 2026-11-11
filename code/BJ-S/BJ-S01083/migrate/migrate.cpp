#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 * 2 + 5;
int c, t;
int n, d;
int x[N], y;
int ans, wh;

int main () {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;

    for (int i = 1; i <= t; i++) {
        cin >> n >> d;
        for (int j = 1; j <= n; j++) {
            cin >> x[j];
        }
        if (d == 1) {
            cout << 1 << '\n';
            continue;
        }
        y = d % 2;
        for (int j = 1; j < n; j++) {
            for (int l = j + 2; l <= n; l++) {
                if ((x[l] - x[j]) > d && (x[l] - x[j]) / d == 1 && ((x[l] - x[j]) % 2 == 1 || d % 2 == 0)) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
        for (int j = 1; j <= n; j++) {
            x[j] = 0;
        }
        ans = 0;
    }

    return 0;
}

