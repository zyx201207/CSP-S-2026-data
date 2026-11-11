#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using i64 = int64_t;

namespace S1 { // 1-10 O(n^2)
	void slv() {
		u32 n;
		i64 d;
		std::vector<i64> x;
		std::cin >> n >> d;
		x.resize(n);
		for (u32 i = 0; i < n; ++i) {
			std::cin >> x[i];
		}
		std::vector<u32> dis(n);
		std::vector<u64> dp(n), dppre(n);
		u32 ans = 0;
		for (u32 L = 0, R = 1; L < n; L = (R++)) {
			while (R < n && x[R] - x[R - 1] <= d) {
				++R;
			}
			// std::cerr << "[" << L << "," << R << "]\n";
			for (u32 i = L; i < R; ++i) {
				// solve for i
				// dis
				u32 l = i;
				dis[i] = 0;
				for (u32 j = i + 1; j < R; ++j) {
					while (x[j] - x[l] > d) {
						++l;
					}
					dis[j] = dis[l] + 1;
				}
				// dp
				l = i;
				u32 r = i;
				for (u32 j = i; j < R; ++j) {
					// std::cerr << i << ' ' << j << std::endl;
					if (x[j] - x[i] <= d) {
						dp[j] = 1;
						dppre[j] = j - i + 1;
						continue;
					}
					while (x[j] - x[l] > d) {
						++l;
					}
					r = std::max(r, l);
					while (r < j - 1 && dis[r + 1] == dis[l]) {
						++r;
					}
					dp[j] = dppre[r] - (l ? dppre[l - 1] : 0);
					// std::cerr << l << ' ' << r << ' ' << dp[j] << std::endl;
					dppre[j] = dppre[j - 1] + dp[j];
					if (dp[j] == 2) {
						++ans;
					}
				}
			}
		}
		std::cout << ans << std::endl;
	}
}

namespace S2 { // 11-12 A
	void slv() {
		u32 n;
		u64 d;
		std::cin >> n >> d;
		if (n == 1) {
			std::cout << "0" << std::endl;
			return;
		}
		i64 x1 = 0, x2 = 0;
		for (u32 i = 1; i <= n; ++i) {
			x1 = x2;
			std::cin >> x2;
		}
		u64 dif = static_cast<u64>(x2 - x1);
		d /= dif;
		if ((d == 0) || (d == 1) || 2 * d - 1 >= n) {
			std::cout << "0" << std::endl;
		} else {
			std::cout << n - (2 * d - 1) << std::endl;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	 freopen("migrate.in", "r", stdin);
	 freopen("migrate.out", "w", stdout);
	u32 c, T;
	std::cin >> c >> T;
	while (T--) {
		if (c <= 10) {
			S1::slv();
		} else if (c <= 12) {
			S2::slv();
		}
	}
	return 0;
}
