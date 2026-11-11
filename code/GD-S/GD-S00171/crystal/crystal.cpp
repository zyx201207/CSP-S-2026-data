#include <bits/stdc++.h>

using ll = long long;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	ll n, m;
	std::cin >> n >> m;
	
	std::vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.begin() + n + 1);
	
	std::vector<ll> q(n + 1);
	for (int i = 1; i <= n; i++) {
		q[i] = q[i - 1] + a[i];
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, res = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) - (q[i] - q[mid - 1]) <= m) {
				res = mid, r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = std::max(ans, i - res + 1);
	}
	
	std::cout << ans << "\n";
	return 0;
}
