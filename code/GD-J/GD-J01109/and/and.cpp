#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, a[N], ans;

void dfs(int x, int cnt, int k) {
	if (cnt < ans && k != 0) return ;
	if (k == m) {
		ans = cnt;
		return ;
	}
	if (n - x + 1 + k < m) return;
	dfs(x + 1, cnt, k);
	if (k == 0) dfs(x + 1, a[x], k + 1); 
	else dfs(x + 1, cnt & a[x], k + 1);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	dfs(1, 0, 0);
	printf("%d", ans);
	return 0;
}
