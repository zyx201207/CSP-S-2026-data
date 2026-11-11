#include<bits/stdc++.h>
#define LL long long
#define PLL pair<LL, LL>
#define PLI pair<LL, int>
#define PIL pair<int, LL>
#define PII pair<int, int>
using namespace std;
const int N = 5e5;
int n;
LL m, a[N + 5], sum[N + 5];

inline void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = 1, ans = 1;
    for (int i = 1; i <= n; i++) {
        while (a[i] * (i - l + 1) - (sum[i] - sum[l - 1]) > m) l++;
        ans = max(ans, i - l + 1);
    }
    cout << ans << "\n";
}
signed main() {
    // freopen("crystal4.in", "r", stdin);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
    return 0;
}