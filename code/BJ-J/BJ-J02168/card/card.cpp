// ========== ACACACACAC ==========
// This is T4.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
const int M = 3e5 + 5;

int n, m;
int a[N], d[M], ans[N];

inline void solve() {
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = n; i >= 1; --i) {
        if (d[a[i]] == -1) {
            d[a[i]] = i;
        } else {
            for (int j = 1; j <= m; ++j) {
                if (d[a[i]] > d[j] && d[j] > i) {
                    ans[j] += d[j] - i;
                    d[j] = -1;
                }
            }
        }
    }

    for (int j = 1; j <= m; ++j) {
        if (d[j] != -1) ans[j] += d[j];
        cout << ans[j] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}