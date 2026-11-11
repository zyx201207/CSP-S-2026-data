#include <iostream>
int c, t, n;
long long d, x[2000005], ans;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::cin >> c >> t;
	while (t--) {
		std::cin >> n >> d;
		for (int i = 0; i < n; ++i) std::cin >> x[i];
		if (c == 11 || c == 12) { // 特殊性质A
			if (n == 1) {
				std::cout << 0;
			} else {
				if ((x[1] - x[0]) * 3 > d && (x[1] - x[0]) * 2 <= d)
					std::cout << std::max(0, n - 3) << '\n';
				else
					std::cout << 0 << '\n';
			}
		} else { // 错误的解法 
			ans = 0;
			for (int i = 0, t1, t2; i + 3 < n; ++i) {
				if (x[i + 3] - x[i] > d && x[i + 2] - x[i] <= d && x[i + 3] - x[i + 1] <= d) {
					t1 = 1;
					while (i - t1 >= 0 ? x[i - t1 + 1] - x[i - t1] <= d && x[i - t1 + 2] - x[i - t1] > d : false) --t1;
					t2 = 1;
					while (i + t2 + 3 < n ? x[i + t2 + 3] - x[i + t2 + 2] <= d && x[i + t2 + 3] - x[i + t2 + 1] > d : false) ++t2;
					ans += t1 * t2;
				}
			}
			std::cout << ans << '\n';
		}
	} 
}
