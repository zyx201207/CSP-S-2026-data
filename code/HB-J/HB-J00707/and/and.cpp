#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n, m, a[N], ans = 2147483647, book[35], k, maxn;

bool cmp(int x, int y) {
	return x > y;
}

void dfs(int x, int now, int step) {
	if (step >= m) {
		maxn = max(maxn, now);
		return;
	}
	if (x >= n) return;
	if (now <= maxn) return;
	dfs(x + 1, now & a[x], step + 1);
	dfs(x + 1, now, step);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == m) {
		int tmp = a[1];
		for (int i = 2; i <= n; i++) {
			tmp &= a[i];
		}
		cout << tmp;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	if (m == 1) {
		cout << a[1];
		return 0;
	}
	dfs(1, 2147483647, 0);
	cout << maxn;
	return 0;
}

