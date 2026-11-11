#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int x[N], dp[N], s[N];
map<pair<int, int>, int> mp;
set<int> se[N];
void solve() {
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        //s[i] = s[i-1] + x[i];
    }
    memset(s, 0x3f, sizeof s);
    memset(dp, 0, sizeof dp);
    mp.clear();
    int ans = 0;
    s[1] = 0;
    for (int u = 1; u <= n; u++) {
        deque<int> q;
        q.push_back(u);
        for (int v = u + 1; v <= n; v++) {
            while (!q.empty() && x[v] - x[q.front()] > d) q.pop_front();
            while (!q.empty() && s[q.back()] > s[v]) q.pop_back();
            if (q.empty()) {
                q.push_back(v);
                continue;
            }
            int y = q.front();
            if (s[v] > s[y] + 1) {
                se[v].clear();
                dp[v] = 0;
            }
            dp[v] = dp[u] + (s[v] == s[y] + 1);
            s[v] = min(s[v], s[y] + 1);
            if (s[v] == s[y] + 1) {
                se[v].insert(y);
            }
            if (se[v].size() > 2) {
                dp[v] = 0;
            }
            //printf("(%lld,%lld): s[%lld] = %lld, s[%lld] = %lld, ", y, v, y, s[y], v, s[v]);
            //printf("dp[%lld] = %lld, dp[%lld] = %lld, size = %lld\n", y, dp[y], v, dp[v], se[v].size());
            q.push_back(v);
        }

    }
    for (int v = 1; v <= n; v++) ans += dp[v];
    cout << ans << '\n';
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--) solve();
    return 0;
}
