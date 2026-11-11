#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, m, ans = -INT_MAX;
int a[N + 3];
bool vis[N + 3];
bool cmp (int u, int w) {
	return u > w;
}
void dfs (int now, int cnt) {
	if (now > m) {
		ans = max (ans, cnt);
		return ;
	}
	if (now == 1) {
		for (int i = 1; i <= n; i ++) {
			vis[i] = 1;
			dfs (now + 1, a[i]);
			vis[i] = 0;
		}
	}
	else {
		for (int i = 1; i <= n; i ++) {
			if (vis[i]) continue;
			vis[i] = 1;
			dfs (now + 1, (cnt & a[i]));
		}
	}
	return ;
}
int main () {
	 freopen ("and.in", "r", stdin);
	 freopen ("and.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);cout.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + n + 1,  cmp);
	dfs (1, 0);
	cout << ans;
	return 0;
}
