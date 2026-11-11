#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e16;
int n, m, a[500010], s[500010], l, r, mid;

inline bool check(int x) {
	for (int i = 1; i + x - 1 <= n; i++)
		if (s[i + x - 1] - (i - 1) * (a[i + x - 1] - a[i - 1]) - s[i - 1] <= m)
			return true;
	return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	l = 0, r = n + 1;
	while (l + 1 < r) {
		mid = (l + r) >> 1;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%lld\n", l);
	return 0;
}
