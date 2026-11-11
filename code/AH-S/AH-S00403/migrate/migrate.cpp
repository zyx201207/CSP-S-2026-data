#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 5;
ll c, t, n, d, ans = 0;
ll a[N], dp[N];
struct emm {
    ll p, v;
};
ll bfs(int s, int e) {
    ll cnt = 1, mi = 1e18;
    bool vis[N];
    memset(dp, 0x3f, sizeof dp);
    memset(vis, 0, sizeof vis);
    queue<emm> q;
    q.push({s, 0});
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        if (x.p == e) {
            if (x.v < mi) {
                cnt = 1;
                mi = x.v;
            } else if (x.v == mi) {
                cnt++;
            }
            continue;
        }
        for (int i = x.p + 1; i <= e; i++) {
            if (a[i] - a[x.p] <= d && x.v + 1 <= dp[i]) {
                q.push({i, x.v + 1});
                dp[i] = x.v + 1;
            } else {
                break;
            }
        }
    }
    return cnt;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                ll s = bfs(i, j);
                if (s == 2) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
	}
	return 0;
}
