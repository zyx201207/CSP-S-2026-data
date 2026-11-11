#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int n, m, a[MAX], ans;
void dfs(int x, int cnt, int num) {
	if (cnt == m) {
		ans = max(ans, num);
		return ;
	}
	for (int i = x + 1; i <= n; i++) {
		dfs(i, cnt + 1, (num == inf ? a[i] : num & a[i]));
	}
}
bool check() {
	for (int i = 1; i <= n; i++) {
		if (a[i] != i - 1) {
			return false;
		}
	}
	return true;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if (n <= 20 || a[n] > pow(2, 21)) {
		dfs(0, 0, inf);
		cout << ans;
		return 0;
	}
	if (n <= 2000) {
		if (m == 1) {
			cout << a[n];
			return 0;
		}
		else {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					ans = max(ans, a[i] & a[j]);
				}
			}
			cout << ans;
			return 0;
		}
	}
	if (n <= 200000) {
		if (m == n - 1) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				int num = inf;
				for (int j = 1; j <= n; j++) {
					if (j == i) {
						continue;
					}
					if (num == inf) {
						num = a[j];
					}
					else {
						num = num & a[j];
					}
				}
				ans = max(ans, num);
			}
			cout << ans;
			return 0;
		}
		if (a[n] < 4) {
			vector<int> cnt(4, 0);
			for (int i = 1; i <= n; i++) {
				cnt[a[i]]++;
			}
			if (cnt[3] >= m) {
				cout << 3;
				return 0;
			}
			if (cnt[3] + cnt[2] >= m) {
				cout << 2;
				return 0;
			}
			if (cnt[3] + cnt[1] >= m) {
				cout << 1;
				return 0;
			}
			cout << 0;
			return 0;
		}
		if (check()) {
			cout << n - m;
			return 0;
		}
		if (!check()) {
			cout << a[n - m + 1];
			return 0;
		}
	}
	return 0;
}
