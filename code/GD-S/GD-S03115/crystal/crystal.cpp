#include <algorithm>
#include <iostream>
#include <cstdio>
#define int long long

using namespace std;

const int N = 5e5 + 10;

int n, m;
int a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i ++ )
		scanf("%lld", a + i);
	sort(a + 1, a + n + 1);
	int l = 1, cnt = 0, ans = 1;
	for (int r = 1; r <= n; r ++ ) {
		cnt += (a[r] - a[r - 1]) * (r - l);
		while (l < r && cnt > m)
			l ++ , cnt -= a[r] - a[l];
		ans = max(ans, r - l + 1);
	}
	printf("%lld\n", ans);
	return 0;
}
