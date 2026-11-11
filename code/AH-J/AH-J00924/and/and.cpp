#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 3e1 + 5;
int n, m, a[N], num, ans, tot, sum[M], use;
bool cmp(int x, int y) {
	return x > y;
}
void solve1() {
	int maxn = -1;
	for (int st = 0; st < (1 << n); st++) {
		int res = (1 << 30) - 1, cnt = 0;
		for (int i = 0; i < n; i++)
			if (((1 << i) & st) > 0) {
			cnt++;
			res = res & a[i + 1];
		}
		if (cnt == m) maxn = max(maxn, res);
	}
	cout << maxn;
	return ;
}
void solve2() {
	int maxn = -1;
	for (int st = 0; st < (1 << use); st++) {
		int res = (1 << 30) - 1, cnt = 0;
		for (int i = 0; i < use; i++)
			if (((1 << i) & st) > 0) {
			cnt++;
			res = res & a[i + 1];
		}
		if (cnt == m) maxn = max(maxn, res);
	}
	cout << maxn;
	return ;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) tot++;
	}
	if (n - tot < m) {
		cout << 0;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	if (m == 1) {
		cout << a[1];
		return 0;
	}
	while ((1 << num) < n) num++;
	if ((1 << num) == n) {
		cout << (m == 2 ? n - 2 : n - 1);
		return 0;
	}
	if (n <= 20) {
		solve1();
		return 0;
	}
	if (n == m) {
		ans = (1 << 30) - 1;
		for (int i = 1; i <= n; i++) ans &= a[i];
		cout << ans;
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) ans = max(ans, a[i] & a[j]);
		cout << ans;
		return 0;
	}
	if (m == n - 1) {
		int res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 30; j++) sum[j] += ((a[i] & (1 << j)) > 0);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 30; j++)
				if (sum[j] - ((a[i] & (1 << j)) > 0)) res += (1 << j);
			ans = max(ans, res);
		}
		cout << ans;
		return 0;
	}
	int sum_ = 0;
	for (int i = 1; a[i] > 0 && i <= n; i++) {
		sum_ += a[i];
		use++;
	}
	if (sum_ <= 4) {
		solve2();
		return 0;
	}
	return 0;
}
