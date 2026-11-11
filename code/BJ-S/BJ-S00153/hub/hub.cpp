#include <bits/stdc++.h>
using namespace std;
long long c, t, n, k, x, y, Min = 2147483647;
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> k;
        for (int j = 1; j <= n - 1; j++) {
            cin >> x >> y;
            Min = min(Min, y);
        }
        cout << Min / 2 << '\n';
    }

    return 0;
}
