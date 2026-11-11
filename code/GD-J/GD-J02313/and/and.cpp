#include <bits/stdc++.h>
using namespace std;
int n, m, ans, a[200005], cnt, maxn;
void dfs (int step, int sum, int idx) {
	if (step > m) {
		ans = max(ans, sum);
		return;
	}
	if (idx > n) return; 
	dfs(step+1, sum&a[idx], idx+1);
	dfs(step, sum, idx+1);
}
bool cmp (int a, int b) {
	return a > b; 
}
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		maxn = max(maxn, a[i]);
		int temp = 1; 
		for (int j = 0; j < 30; j++) {
			if (a[i] == temp-1) cnt++;
			temp *= 2;
		}
	}
	sort (a+1, a+n+1, cmp);
	if (n <= 20) {
		dfs(1, 1073741823, 1);
		printf ("%d", ans);
		return 0;
	}
	if (m == 1) {
		printf ("%d", a[1]);
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++)
			for (int j = i+1; j <= n; j++)
				ans = max(ans, a[i]&a[j]);
		printf ("%d", ans);
		return 0;
	}
	if (m == n) {
		ans = 1073741823;
		for (int i = 1; i <= n; i++) ans &= a[i];
		printf ("%d", ans);
		return 0;
	}
	if (cnt == n) {
		ans = 1073741823;
		for (int i = 1; i <= m; i++) ans &= a[i];
		printf ("%d", ans);
		return 0;
	}
	if (maxn < 4) {
		ans = 1073741823;
		for (int i = 1; i <= m; i++) ans &= a[i];
		printf ("%d", ans);
		return 0;
	}
	return 0;
}
