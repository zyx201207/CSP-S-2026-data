#include<bits/stdc++.h>

using namespace std;

const int N = 2010;

int n, m, a[N], dp[N][N], mx, ans;
bool vis[N];

void solve1() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			for (int k = 2; k <= min(i, m); ++k) {
				dp[i][k] = max(dp[i][k], a[i] & dp[j][k - 1]);
			} 
		}
	}
	cout << dp[n][m] << endl;
}

void dfs(int num, int sum) {
	if (num == m + 1) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(num + 1, sum & a[i]);
			vis[i] = 0;
		} 
	}
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int tpp =0 ;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i == 1) tp = a[i];
		mx = max(mx, a[i]);
		dp[i][1] = mx;
		tp &= a[i];
	}
	if (m == 1) {
		cout << mx << endl;
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) continue;
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans << endl;
		return 0;
	}
	if (n <= 20) {
		for (int i = 1; i <= n; ++i) {
			dfs(1, a[i]);
		}
		cout << ans << endl;
		return 0;
	}
	if (m == n - 1) {
		int res = a[1]; 
		for (int i = 2; i < n; ++i) {
			res &= a[i];
		}
		ans = max(ans, res);
		res = a[2];
		for (int i = 3; i <= n; ++i) {
			res &= a[i];
		}
		ans = max(ans, res);
		cout << ans << endl;
		return 0;
	}
	if (n == m) {
		cout << tp;
	}
	return 0;
}

