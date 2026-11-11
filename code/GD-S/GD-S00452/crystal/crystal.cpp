#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
	// std::clock_t stTime = std::clock();

	std::freopen("crystal.in", "r", stdin);
	std::freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; i64 m;
	std::cin >> n >> m;

	std::vector<i64> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());

	std::vector<i64> sum(n + 1);
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + a[i];
	}

	int ans = 0;
	for (int r = 1; r <= n; ++r) {
		int lo = -1, hi = r;
		auto check = [&](int l) -> bool {
			return a[r - 1] * (r - l) - (sum[r] - sum[l]) <= m;
		};
		while (lo + 1 < hi) {
			auto mid = (lo + hi) >> 1;
			if (check(mid)) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		ans = std::max(ans, r - hi);
	}
	std::cout << ans << "\n";

	// std::cerr << 1. * (std::clock() - stTime) / CLOCKS_PER_SEC << "\n";

	return 0;
}

/*
freopen	--- 1 crystal
integer	--- 1 all i64
corner	--- 1 binary limits (-1, r]
limit   --- 0

time	--- 1 nlogn(n = 5e5)	/// 1s
memory	--- 1 16n + O(1) 		/// 1024MB

duipai	--- 0
*/