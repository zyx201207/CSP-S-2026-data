#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using i128 = __int128;

using PII = pair<int, int>;
using PLL = pair<ll, ll>;

#define rep(i, j, k) for (int (i) = (j); (i) < (k); (i)++)
#define __rrep(i, j, k) for (int (i) = (j); (i) <= (k); (i)++)

constexpr ll inf = (1ll << 62);
constexpr int N = 5e5 + 10;

template <typename T> void chkmax(T& a, T b) { a = max(a, b); }
template <typename T> void chkmin(T& a, T b) { a = min(a, b); }

int n;
ll m, a[N], s[N];

bool check(int i, int j) {
    ll cur = s[j] - (!i ? 0 : s[i - 1]);
    return (1ll * (j - i + 1) * a[j] - cur) <= m;
}

void solve() {
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> a[i];
    }

    sort(a, a + n);
    rep(i, 0, n) {
        s[i] = (!i ? 0 : s[i - 1]) + a[i];
    }

    int ans = 1;
    rep(i, 0, n) {
        int l = 0, r = i;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, i)) r = mid;
            else l = mid + 1;
        }
        chkmax(ans, i - l + 1);
    }
    
    cout << ans << "\n";
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
