// ========== ACACACACAC ==========
// This is T1.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5 + 5;

int n; ll m, a[N];
int ans = 1;

inline void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int mid = n >> 1;
    for (int i = mid + 1; i <= n; ++i) {
        if (a[i] - a[mid] > m) break;
        m -= (a[i] - a[mid]);
        ++ans;

        if (a[i] - a[mid] > m || (!(n & 1) && i == n)) break;
        m -= (a[i] - a[mid]);
        ++ans;
    }
    cout << ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}