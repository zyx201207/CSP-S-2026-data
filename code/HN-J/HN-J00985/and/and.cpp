#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, pre[N], a[N], m, ans, mx;

void dfs(int i, int sum, int x) {
	if (x == m) {
		ans = max(ans, sum);
		return ;
	}
	if (i == n) {
		return;
	}
	dfs(i + 1, sum, x);
	dfs(i + 1, sum & a[i + 1], x + 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	int b = a[1];
	for (int i = 2; i <= n; i++) {
		b &= a[i];
	}
	if (m == 1) {
		cout << mx;
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if (m == n) {
		cout << b;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, a[i], 1);
	}
	cout << ans;
	return 0;
}
