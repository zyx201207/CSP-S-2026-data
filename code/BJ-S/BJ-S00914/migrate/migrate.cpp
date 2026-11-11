#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;

int c, t, cnt, ch, cn1;
int n, m;
int a[N];

bool f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cnt = 0;
        cin >> n >> m;
        a[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i >= 3) {
                if (ch != a[i] - a[i - 1]) f = true;
            }
            if (i >= 2) ch = a[i] - a[i - 1];
        }
        if (!f) {
            if (n <= 3) {
                cout << 0 << "\n";
                continue;
            }
            for (int i = 1; i <= n; i++) {
                if (i == (2 * m)) cnt++;
            }
            cout << cnt * max(1, ((n % 2) * 2))<< "\n";
        }
    }
    return 0;
}
