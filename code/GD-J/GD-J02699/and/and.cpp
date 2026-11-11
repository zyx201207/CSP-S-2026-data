#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 114514;
int n, m, a[N], ans = 0;

bool cmp(int x, int y) {
	return x > y;
}

bool check_B() {
	for (int i = 1; i <= n; i++)
		if (a[i] != i - 1)
			return false;
	return true;
}

void solve1() {
	sort(a + 1, a + n + 1);
	cout << a[n] << "\n";
}

void solve2() {
	ans = a[1];
	for (int i = 1; i <= n; i++)
		ans &= a[i];
	cout << ans << "\n";
}

void solve3() {
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans = max(ans, a[i] & a[j]);
	cout << ans << "\n";
}

void solve4() {
	cout << n - 1 << "\n";
}

void solve5() {
	sort(a + 1, a + n + 1);
	cout << a[n - m + 1] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	if (m == 1) {
		solve1();
	} else if (m == n) {
		solve2();
	} else if (m == 2) {
		solve3();
	} else if (check_B()) {
		solve4();
	} else {
		solve5();
	}
	
	return 0;
}

