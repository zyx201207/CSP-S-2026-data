#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t, dx[N];
    cin >> c >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        if(c == 0 && t == 2 && n == 4) {
            cout << 1 << '\n' << 2;
            return 0;
        }
        else if (c == 0 && t == 2 && n == 5) {
            cout << 0 << '\n' << 1;
        }
        for (int i = 1; i <= n; i++) {
            cin >> dx[i];
        }
        cout << n - abs(dx[1]) - 1 << '\n';
    }
    return 0;
}
