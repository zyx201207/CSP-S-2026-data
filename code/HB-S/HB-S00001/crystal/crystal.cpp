#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace stdp {
    const int N = 5e5;
    int n, m;
    int a[N + 5], pre[N + 5];
    bool check(int x) {
        for (int i = x; i <= n; i++) {
            if (a[i] * (x - 1) - (pre[i - 1] - pre[i - x]) <= m) {
                return 1;
            }
        }
        return 0;
    }
    void main() {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << "\n";
    }
}

signed main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int t = 1;
    // cin >> t;

    while (t--) stdp::main();
    return 0;
}

// remind to use ll
