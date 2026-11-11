#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
int n, m, ans, tot;
int a[MAXN];
void dfs(int now, int s, int res) {
	if (s >= m) {
		ans = max(ans, res);
		return ;
	}
	if (now > n) return ;
	dfs(now + 1, s, res);
	dfs(now + 1, s + 1, res & a[now]);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		tot = max(tot, a[i]);
	}
	if (m == n) {
		tot = a[1];
		for (int i = 2; i <= n; i++) tot &= a[2];
		printf("%d\n", tot);
		return 0;
	}
	if (m == 1) {
		printf("%d\n", tot);
		return 0;
	}
	dfs(1, 0, 1073741823);
	printf("%d\n", ans);
}
