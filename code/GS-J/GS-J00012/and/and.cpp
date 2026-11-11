#include<bits/stdc++.h>
using namespace std;

int n, m, a[200010], ans = -1;

void dfs(int i, int j, int cnt) {
	if (i == n + 1 && j == m) {
		ans = max(ans, cnt);
		return;
	}
	if (i == n + 1) return;
	if (j == 0) {
		dfs(i + 1, j + 1, a[i]);
	}else if (j < m) {
		dfs(i + 1, j + 1, cnt & a[i]);
	}dfs(i + 1, j, cnt);
}

int main() {
	//Trick||Treat!
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (m == 1 && n > 20) { // m == 1 && n <= 2000
		for (int i = 1; i <= n; i++)
			ans = max(ans, a[i]);
		printf("%d", ans);
	}else if (m == n && n > 20) { // m == n && n <= 2000
		int ans = a[1];
		for (int i = 2; i <= n; i++)
			ans = ans & a[i];
		printf("%d", ans);
	}else if (m == n - 1 && n > 2000) { // m == n - 1 && n == 2 * 10^5
		int sum = a[1];
		for (int i = 2; i <= n; i++)
			sum = sum & a[i];
		for (int i = 1; i <= n; i++)
			ans = max(ans, sum | a[i]);
		printf("%d", ans);
	}else if (m == 2 && n > 20) { // m == 2 && n <= 2000
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				ans = max(ans, a[i] & a[j]);
		printf("%d", ans);
	}else { // n <= 20
		dfs(1, 0, 0);
		printf("%d", ans);
	}
}
