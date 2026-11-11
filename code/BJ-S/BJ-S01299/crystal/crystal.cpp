#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 5e5 + 25;
ll s[maxn], h[maxn], m;
int n;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    sort(h + 1, h + n + 1);
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + h[i];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        auto std = h[i];
        auto isvalid = [&](auto x) {
            return s[i - x - 1] - s[i] <= m - 1ll * (x + 1) * std;
        };
        int l = 0, r = i - 1, mid, ans = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (isvalid(mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        res = max(res, ans + 1);
    }
    cout << res << '\n';
    return 0;
}