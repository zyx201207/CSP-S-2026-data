#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int ans = 0;
int a[500010];

 main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort (a + 1, a + 1 + n);

    int base = 0;
    if (n % 2 == 0) base = n / 2;
    else base = ceil(n / 2);

    for (int i = 1; i <= n; i++) {
        if (a[i] != a[base]) {
            int used = abs(a[base] - a[i]);
            if (m >= used) m -= used;
            else break;

            if (a[i] < a[base]) a[i] += used;
            else if (a[i] > a[base]) a[i] -= used;
        }
    }

    for (int i = 1; i <= n; i++)
        if (a[i] == a[base]) ans++;

    cout << ans << endl;

    return 0;
}
