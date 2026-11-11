#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], mx, ans, vis[N];
void dfs(int now, int tot) {
	if (now == m + 1) {
		ans = max(tot, ans);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (now == 1) {
				vis[i] = 1;
				dfs(now + 1, a[i]);
				vis[i] = 0;
			}
			else {
				vis[i] = 1;
				dfs(now + 1, tot & a[i]);
				vis[i] = 0;
			}
		}
	}
	return ;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if (n <= 20) {
		dfs(1, 0);
		cout << ans;
	}
	else if (m == 1) {
		cout << mx;
	}
	else if (m == n) {
		ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans = (ans & a[i]);
		}
		cout << ans;
	}
	else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					ans = max(ans, a[i] & a[j]);
				}
			}
		}
		cout << ans;
	}
	else if (mx <= 4) {
		int box[5] = {};
		for (int i = 1; i <= n; i++) {
			box[i]++;
		}
		if (box[4] >= m) {
			cout << 4;
		}
		else if (box[3] >= m) {
			cout << 3;
		}
		else if (box[3] + box[2] >= m) {
			cout << 2;
		}
		else if (box[3] + box[1] >= m) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else {
		sort(a + 1, a + n + 1);
		ans = a[n];
		int cnt = n - 1;
		while (m--) {
			ans = a[cnt];
		}
		cout << ans;
	}
	return 0;
}
