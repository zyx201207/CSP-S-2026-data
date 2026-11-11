#include <bits/stdc++.h>

using i64 = long long;

void R() {
	int n;
	i64 d;
	std::cin >> n >> d;
	constexpr int N = 2000010;
	static std::array<i64, N> x;
	for (int i = 0; i < n; i++) {
		std::cin >> x[i];
	}
	i64 t = d / (x[1] - x[0]), res = 0;
	for (int i = 1; i < t && n - t - i > 0; i++)
		res += n - t - i;
	std::cout << res << "\n";
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int c, T = 1;
	std::cin >> c >> T;
	while (T--)
		R();
	return 0;
}
