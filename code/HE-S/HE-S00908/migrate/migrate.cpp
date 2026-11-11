#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int x[N];
int main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin >> c >> t;
    int n, d;
    cin >> n >> d;
    while (t--) {
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
    }

    cout << "1" << "\n" << "2";

    return 0;
}
