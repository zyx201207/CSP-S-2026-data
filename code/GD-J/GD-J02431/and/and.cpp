#include <iostream>

using namespace std;

const int N = 200010;

int n, m, ans, a[N], dp[N];

void dfs(int idx, int cnt, int res) {
	if (idx == n + 1) {
		if (cnt == m) {
			ans = max(ans, res);
		}
		return;
	}
	
	dfs(idx + 1, cnt, res);
	dfs(idx + 1, cnt + 1, res & a[idx]);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	if (m == 1) {
		ans = a[1];
		for (int i = 2; i <= n; ++i) {
			ans = max(ans, a[i]);
		}
		cout << ans;
		return 0;
	}
	
	if (m == 2) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	
	if (n % 2 == 0) {
		bool flagb = true;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != i - 1) {
				flagb = false;
			}
		}
		if (flagb) {
			ans = a[n];
			for (int i = n - 1; i > n - m; --i) {
				ans &= a[i];
			}
			cout << ans;
			return 0;
		}
	}
	
	if (m == n) {
		ans = a[1];
		for (int i = 2; i <= n; ++i) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	
	dfs(1, 0, (1 << 30) - 1);
	
	cout << ans;
	
	return 0;
}
