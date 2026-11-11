#include <bits/stdc++.h>

using i64 = long long;

void R() {
	int n;
	i64 m;
	std::cin >> n >> m;
	constexpr int N = 500010;
	static std::array<i64, N> a;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(a.begin(), a.begin() + n);
	int res = 0;
	i64 s = 0;
	for (int i = 1, j = 0; i < n; i++) {
		if (i > 0) {
			s += (a[i] - a[i - 1]) * (i - j);
		}
		if (s > m) {
			s -= a[i] - a[j];
			j++;
		}
		res = std::max(res, i - j + 1);
	}
	std::cout << res << "\n";
	return;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T = 1;
//	std::cin >> T;
	while (T--)
		R();
	return 0;
}
