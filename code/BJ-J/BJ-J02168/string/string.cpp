// ========== ACACACACAC ==========
// This is T2.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int n;
ll a[N], sum;
char c[N];

inline void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
        sum += a[i];
    }
    ll tmp = a[1], ans = 0;
    int nowr = n;
    sum >>= 1;
    for (int i = 1; i <= n; ++i, tmp += a[i]) {
    // for (int i = 1; i <= n; ++i) {
        ll mn = 0;
        if (tmp > sum) mn = tmp - sum;
        while (a[i] > mn) {
            if (a[nowr] <= a[i] - mn) {
                ans += ((c[nowr] == c[i]) ? 0 : a[nowr]);
                a[i] -= a[nowr];
                a[nowr] = 0;
                --nowr;
            } else {
                ans += ((c[nowr] == c[i]) ? 0 : a[i] - mn);
                a[i] = mn;
                a[nowr] -= a[i] - mn;
            }
        }
        // if (mn != 0) break;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}