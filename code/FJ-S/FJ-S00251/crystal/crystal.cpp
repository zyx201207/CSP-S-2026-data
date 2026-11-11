#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
int n, m, p, s, tp, ans;
int a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1); 
	tp = a[1], p = 1, s = 0;
	for (int i = 1; i <= n; i++) {
		int c = a[i] - tp;
		s += (i - p) * c;
		while (s > m && p <= i) {
			s -= (a[i] - a[p]);
			p++;
		}
		ans = max(ans, i - p + 1);
		tp = a[i];
	}
	printf("%lld", ans);
	return 0;
}
