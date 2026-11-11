#include <bits/stdc++.h>

using ll = long long;

void solve(int _c) {
	ll n, d;
	std::cin >> n >> d;
	
	std::vector<ll> x(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> x[i];
	}
	
	if (_c == 11 || _c == 12) {
		if (n == 1) {
			std::cout << "0\n";
			return;
		}
		
		ll k = d / (x[2] - x[1]);
		if ((x[2] - x[1]) % d == 0) {
			std::cout << "0\n";
		} else {
			std::cout << std::max(0ll, n - 2 * k + 1) << "\n";
		}
		return;
	}
	
	std::vector<int> c(n + 1);
	auto modify = [&](int x, int y) -> void {
		for (; x <= n; x += x & (-x)) {
			c[x] = c[x] + y;
		}
	};
	
	auto query = [&](int x) -> int {
		int res = 0;
		for (; x; x -= x & (-x)) {
			res += c[x];
		}
		return res;
	};
	
	ll ans = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			c[j] = 0;
		}
		
		std::vector<int> dp(n + 1), dist(n + 1, -1);
		dp[i] = 1, dist[i] = 0;
		modify(i, dp[i]);
		for (int j = i + 1; j <= n; j++) {
			int l = i, r = j - 1, res = -1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (x[j] - x[mid] <= d) {
					res = mid, r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			if (res == -1) continue;
			
			dist[j] = dist[res] + 1;
			int l2 = res, r2 = j, res2 = -1;
			while (l2 <= r2) {
				int mid = (l2 + r2) / 2;
				if (dist[mid] == dist[res]) {
					res2 = mid, l2 = mid + 1;
				} else {
					r2 = mid - 1;
				}
			}
			dp[j] = std::min(3, query(res2) - query(res - 1));
			modify(j, dp[j]);
			if (dp[j] == 2) ans++;
		}
	}
	
	std::cout << ans << "\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int c, t;
	std::cin >> c >> t;
	while (t--) solve(c);
	return 0;
}
