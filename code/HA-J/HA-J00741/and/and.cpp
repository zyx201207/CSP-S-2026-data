#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000003], maxn = -10909999;
bool vis[1000004];
void dfs(int x, long long sum, int start) {
	if (x >= m) {
		maxn = max(maxn, sum);
		return;
	}
	for (int i = start; i <= n; i ++) {
		sum = a[start];
		if (!vis[i]) {
			vis[i] = true;
			dfs(x + 1, sum & a[i], i);
			vis[i] = false;
		}
	}
}
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	dfs(0, 0, 1);
	cout << maxn;
	return 0;
}
