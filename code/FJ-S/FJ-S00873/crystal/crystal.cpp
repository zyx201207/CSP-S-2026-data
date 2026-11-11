#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N], s;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("crystal1.in", "r", stdin);
//	freopen("crystals.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		s += a[i];
	}
	sort(a + 1, a + n + 1);
	int tt = 0;
	int ans = 0;
	int l = n, r = n;
	while(l >= 1) {
		ans = max(ans, r - l + 1);
		while(tt + a[r] - a[l - 1] > m) {
			tt -= (r - l) * (a[r] - a[r - 1]);
			r--;
		}
		l--;
		tt += a[r] - a[l];
	}
	printf("%lld", ans);
	return 0;
}
