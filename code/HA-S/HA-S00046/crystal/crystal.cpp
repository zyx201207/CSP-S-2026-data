#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int INF = 0x3f3f3f3f, _INF = 0xc0c0c0c0;
const ll LLINF = 0x3f3f3f3f3f3f3f3f, _LLINF = 0xc0c0c0c0c0c0c0c0;

/*
这题是不是有点熟悉来着。

考虑二分。

考虑二分最后的答案。然后你看需要多少次操作。

是不是也不太好弄。

先假设这是贪心。

哦，刚才这个想法是对的吗？

考虑你现在想知道如果要选择 x 颗水晶。

你说的对，但是我读错题了。

只能增加，不能减少。

那就更简单了啊！

还是二分。

然后你考虑比如 1 2 4. 你只需要用前缀和，求出 1 2 之和，再用两个 4 减去它就可以了。 
*/

const int N = 5e5 +10;
int n, m; ll s[N];
ll a[N];


bool check(int x) {
	if (x == 1) {
		return true;
	}
	for (int i = x; i <= n; i++) {
		if (a[i] * (x - 1) - s[i - 1] + s[i - x] <= m) {
			return true;
//			if (x == 3) std::cerr << a[i] * x - s[i - 1] + s[i - x] <<'\n';
		}
	}
	return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false); std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	
	int l = 0, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
//		std::cerr << mid << '\n';
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	
	std::cout << ans << '\n';

	return 0;
}

