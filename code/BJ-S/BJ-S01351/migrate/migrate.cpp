#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace solve1 {
    const int N = 5005;
    int a[N], dp[N], pos[N], s[N], cnt[N];
    int n, d;
    void solve() {
        memset(a, 0, sizeof a);
        memset(pos, 0, sizeof pos);
        memset(dp, 0x3f, sizeof dp);
        memset(cnt, 0, sizeof cnt);
        memset(s, 0, sizeof pos);
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            int l = 1, r = i - 1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (a[i] - a[mid] > d) l = mid + 1;
                else pos[i] = mid, r = mid - 1;
            }
        }
        for (int i = 1; i <= n; i++)
            if (a[i] - a[pos[i]] > d) pos[i] = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(dp, 0x3f, sizeof dp);
            memset(cnt, 0, sizeof cnt);
            memset(s, 0, sizeof pos);
            dp[i] = 0, cnt[i] = 1, s[i] = 1;
            for (int j = i + 1; j <= n; j++) {
                if (pos[j] == 0) continue;
                dp[j] = dp[pos[j]] + 1;
                if (pos[j] < i) pos[j] = i;
                int l = pos[j], r = j - 1, res;
                while (l <= r) {
                    int mid = l + r >> 1;
                    if (dp[mid] > dp[pos[j]]) r = mid - 1;
                    else res = mid, l = mid + 1;
                }
                cnt[j] = s[res] - s[pos[j] - 1];
                if (cnt[j] == 2) {
                    ans++;
                }
                s[j] = s[j - 1] + cnt[j];
            }
        }
        cout << ans << "\n";
    }
}

namespace solvea {
    const int N = 2e6 + 5;
    int a[N];
    int n, d;
    void solve() {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int k = a[2] - a[1];
        int len = d / k * 2;
        if (n - len + 1 < 1 || d <= k) cout << 0 << endl;
        else cout << n - len + 1 << endl;
    }
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    if (c <= 10) {
        while (t--) solve1::solve();
    } else if (c <= 12) {
        while (t--) solvea::solve();
    }
    return 0;
}