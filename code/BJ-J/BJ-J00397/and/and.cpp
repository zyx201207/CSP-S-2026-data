// 6, 7, 8, 9, 10, [11, 12], 13 -> [30, 40]pts;
#include <iostream>
#include <algorithm>
const int MAXN = 2e5 + 5;

int n, m;
int a[MAXN];

void solvem1() {
	int mx = -1;
	for (int i = 1; i <= n; i++)
		mx = std::max(mx, a[i]);
	std::cout << mx << '\n';
}

void solvem2() {
	int mx = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int cur = (a[i] & a[j]);
			mx = std::max(mx, cur);
		}
	std::cout << mx << '\n';
}

void solvemn() {
	int ans = a[1];
	for (int i = 2; i <= n; i++)
		ans &= a[i];
	std::cout << ans << '\n';
}

void solvemn1() {
	int ans = -1e9;
	for (int x = 1; x <= n; x++) {
		int res;
		if (x == 1) res = a[2];
		else res = a[1];
		for (int i = 1; i <= n; i++)
			if (i != x) res &= a[i];
		ans = std::max(ans, res);
	}
	std::cout << ans << '\n';
}

bool chkall1(int x) {
	while (x) {
		if (!(x & 1)) return false;
		x >>= 1;
	}
	return true;
}

void solveall1() {
	std::sort(a + 1, a + n + 1, std::greater<int>());
	std::cout << a[m] << '\n';
}

int main() {
	std::freopen("and.in", "r", stdin);
	std::freopen("and.out", "w", stdout);
	std::cin >> n >> m;
	bool all1 = true;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i], all1 = all1 && (chkall1(a[i]));
	if (m == 1) {
		solvem1();
		return 0;
	} else if (m == 2) {
		solvem2();
		return 0;
	} else if (m == n) {
		solvemn();
		return 0;
	} else if (m == n - 1) {
		solvemn1();
		return 0;
	} else if (all1) {
		solveall1();
		return 0;
	}
	return 0;
}