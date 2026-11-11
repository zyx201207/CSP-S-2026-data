#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6;
long long x[MAXN];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t, n;
    cin >> c >> t;
    while (t--) {
        long long d, diff = -1, res = 0;
        cin >> n >> d;
        int length = 1;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            if (i) {
                if (diff <= d && diff == x[i] - x[i - 1]) length++;
                else {
                    if (d / diff == 2 && length > 2) res += length - 2;
                    diff = x[i] - x[i - 1];
                    length = 1;
                }
            }
        }
        if (d / diff == 2 && length > 2) res += length - 2;
        cout << res << '\n';
    }

    return 0;
}
