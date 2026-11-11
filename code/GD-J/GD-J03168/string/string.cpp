#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	u32 n;
	u64 ans = 0;
	std::vector<std::pair<u32, char>> s;
	std::cin >> n;
	s.resize(n);
	for (u32 i = 0; i < n; ++i) {
		std::cin >> s[i].first >> s[i].second;
	}
	u32 lind = 0, llen = 0, rind = n - 1, rlen = s[n - 1].first;
	while (lind < rind) {
		u32 lrest = s[lind].first - llen, rrest = rlen;
		ans += std::min(lrest, rrest) * (s[lind].second != s[rind].second);
		if (lrest < rrest) {
			rlen -= lrest;
			++lind;
			llen = 0;
		} else if (lrest == rrest) {
			++lind;
			llen = 0;
			--rind;
			rlen = s[rind].first;
		} else {
			--rind;
			rlen = s[rind].first;
			llen += rrest;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
