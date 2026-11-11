#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int sum = 0, ans = 0;
	for (int l = 1, r = 1; r <= n;) {
		sum += a[r++];
		if (a[r] * (r - l) - sum <= m) {
			ans = max(ans, r - l);
		} else {
			sum -= a[l++];
		}
	}
	printf("%d\n", ans);
}
