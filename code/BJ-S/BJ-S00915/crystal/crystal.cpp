#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

long long n, m, ans;
long long a[N];

bool check(int x) {
    for (int i = 1; i <= n - x + 1; i++) {
        long long sum = 0;
        for (int j = 1; j <= x; j++) {
            sum += (a[i + x - 1] - a[i + j - 1]);
        }
        if (sum <= m) {
            // cout << i << " " << sum << "\n";
            return true;
        }
    }
    return false;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // d[i] = a[i] - a[i-1];
    }
    sort(a + 1, a + n + 1);
    long long l = 0, r = n, x;
    while (l <= r) {
        x = (l + r) >> 1;
        if (check(x)) {
           ans = x;
            l = x + 1;
            // cout << "yes " << x << " " << l << "\n";
        }
        else {
            r = x - 1;
            // cout << "no " << x << "\n";
        }
    }
    cout << ans << "\n";
    return 0;
}
