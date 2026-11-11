#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 5;

ll x[N];
ll diff[N];
int nxt[N];
int mins = 1e9;
int cnt = 0;

void dfs(int now, int target, int dist) {
	if (dist > mins) return;
	if (cnt > 2) return;
	if (now == target) {
		if (dist < mins) {
			mins = dist;
			cnt = 1;
		} else if (dist == mins) {
			++cnt;
		}
		return;
	}
	for (int i = now + 1; i <= nxt[now]; ++i) {
		dfs(i, target, dist + 1);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n;
		ll d;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
			if (i > 1) diff[i - 1] = x[i] - x[i - 1];
		}
		if (n <= 3) {
			cout << 0 << '\n';
			continue;
		}
		if (diff[1] == diff[2] && diff[2] == diff[3] && diff[3] == diff[4]) {
			if (d <= diff[1]) {
				cout << 0 << '\n';
				continue;
			}
			ll t = d / diff[1];
			cout << max(1LL * 0, n - 2 * t + 1) << '\n';
		} else if (x[n] - x[1] <= 2 * d) {
			cout << n - 3 << '\n';
		} else if (n <= 300) {
			for (int i = 1; i <= n; ++i) {
				ll y = x[i] + d;
				int idx = lower_bound(x + 1, x + n + 1, y) - x;
				if (x[idx] == y) {
					nxt[i] = idx;
				} else {
					nxt[i] = idx - 1;
				}
			}
			int ans = 0;
			for (int k = 4; k <= n; ++k) {
				for (int i = 1; i <= k - 3; ++i) {
					mins = 1e9, cnt = 0;
					dfs(i, k, 0);
					if (cnt == 2) ++ans;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
} 
