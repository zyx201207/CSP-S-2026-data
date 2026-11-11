#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int n, m;
int ans = 0;

void dfs(int k, int sum, int last) {
	if (k > m) {
		ans = max(ans, sum);
		return;
	}
	if (sum == 0) return;
	for (int i = last + 1;i <= n;i++) {
		if (n - i + 1 + k < m) return;
		dfs(k + 1, sum & a[i], i);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		scanf("%d", a + i);
	}
	dfs(1, INT_MAX, 0);
	printf("%d", ans);
	return 0;
}
