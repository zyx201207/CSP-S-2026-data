#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, m, a[N], maxx;
void dfs(int now, int cnt, int ret) {
	if (cnt == m) {
		maxx = max(maxx, ret);
		return;
	}
	if (now == n + 1) return;
	dfs(now + 1, cnt, ret);
	if (cnt == 0) dfs(now + 1, cnt + 1, a[now]);
	else dfs(now + 1, cnt + 1, ret & a[now]);
}
bool cmp(int x, int y) {
	int cntx = 0, cnty = 0;
	while (x) {
		x &= x - 1;
		cntx++;
	}
	while (y) {
		y &= y - 1;
		cnty++;
	}
	return cntx > cnty;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1) {
		for (int i = 1; i <= n; i++)
			maxx = max(maxx, a[i]);
		cout << maxx;
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				maxx = max(maxx, a[i] & a[j]);
		cout << maxx;
		return 0;
	}
	if (n == m) {
		int sum = a[1];
		for (int i = 2; i <= n; i++)
			sum &= a[i];
		cout << sum;
		return 0;
	}
	if (n <= 25) {
		dfs(1, 0, 0);
		cout << maxx;
		return 0;
	}
	bool flag = true;
	for (int i = 1; i <= n; i++) 
		if (a[i] != (1 << i) - 1) 
			flag = false;
	if (flag || (1 << (int)log2(n)) == n) {
		int ret = a[n];
		for (int i = 1; i < m; i++) 
			ret &= a[n - i];
		cout << ret;
		return 0;
	}
	sort(a + 1, a + 1 + n, cmp);
	int ret = 0;
	for (int i = 1; i <= m; i++) ret &= a[i];
	cout << ret;
	return 0;
}
