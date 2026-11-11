#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500050;
int n, m, i, j, k, a[N], s, l, ans;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (i=1; i<=n; i++) scanf("%lld", &a[i]);
	sort(a+1, a+n+1);
	for (l=i=1; i<=n; i++) {
		s += a[i];
		while (l <= i && (i-l+1)*a[i]-s > m) s -= a[l], l++;
		ans = max(ans, i-l+1);
	}
	printf("%lld\n", ans);
	return 0;
}

