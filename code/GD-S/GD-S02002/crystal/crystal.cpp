#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n;
long long m, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int l = n, ans = 1;
	for (int r = n; r >= 1; r--, m += (r - l + 1) * (a[r + 1] - a[r])) {
		l = min(l, r);
		while (l > 1 && abs(a[r] - a[l - 1]) <= m) {
			m -= abs(a[r] - a[--l]);
		}
		ans = max(ans, r - l + 1);
	}
	printf("%d\n", ans);
	return 0;
} 
