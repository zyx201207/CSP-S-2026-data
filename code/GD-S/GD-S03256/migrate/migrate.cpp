#include <iostream>
#include <vector>

#define int long long

void solve1() {
	int n, d;
	std::cin >> n >> d;
	std::vector<int> x(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> x[i];
	int dif = x[2] - x[1];
	if (d < 2 * dif) {
		std::cout << 0 << '\n';
		return;
	}
	int k = d / dif, ans = 0;
	for (int i = k + 2; i <= 2 * k && i <= n; ++i) {
		ans += n - i + 1;
	}
	std::cout << ans << '\n';
}
void solve2() {
	int n, d;
	std::cin >> n >> d;
	std::vector<int> x(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> x[i];
	std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1, 8e18)), cnt(n + 1, std::vector<int>(n + 1, 8e18));
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (x[j] - x[i] <= d)
				dis[i][j] = dis[j][i] = cnt[i][j] = cnt[j][i] = 1;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				if (i == j || i == k || k == j || dis[i][k] == 8e18 || dis[k][j] == 8e18) continue;
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					cnt[i][j] = 1;
				} else if (dis[i][j] == dis[i][k] + dis[k][j]) {
					++cnt[i][j];
				}
			}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (cnt[i][j] == 2)
				++ans;
	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int c, T;
	std::cin >> c >> T;
	if (c == 11 || c == 12)
		while (T--) solve1();
	else
		while (T--) solve2();

	std::cout << std::flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

