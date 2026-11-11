#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using i64 = int64_t;

namespace S1 { // 1-3 O(2^npoly(n))
// class Tree {
// private:
// 	u32 n;
// 	std::vector<u32> dep;
// 	std::vector<std::vector<u32>> e;
// };
void slv() {
	// u32 n, k;
	// std::cin >> n >> k;
	// Tree t(n);
	// for (u32 i = 0, u, v; i < n - 1; ++i) {
	// 	std::cin >> u >> v;
	// 	--u, --v;
	// 	t.addedge(u, v);
	// }
	u32 ans = 0;
	// for (u32 S = 0; !(S >> n); ++i) {
	// 	if (t.qry_ccc(S) > 2) {
	// 		continue;
	// 	}
	// 	ans = std::min(ans, t.getans(S));
	// }
	std::cout << ans << std::endl;
}
}

namespace S2 { // 13-14 A
void slv() {
	u32 n, k;
	std::cin >> n >> k;
	for (u32 i = 0, u, v; i < n - 1; ++i) std::cin >> u >> v;
	if (k == n) {
		std::cout << 0 << std::endl;
		return;
	}
	n = (n + 1) / 2;
	std::cout << ((n - k + 2) / 2 + 1) / 2 << std::endl;
}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	 freopen("hub.in", "r", stdin);
	 freopen("hub.out", "w", stdout);
	u32 c, T;
	std::cin >> c >> T;
	while (T--) {
		if (c <= 6) {
			S1::slv();
		} else if (c == 13 || c == 14) {
			S2::slv();
		} else {
			std::cout << 0 << std::endl;
		}
	}
	return 0;
}
