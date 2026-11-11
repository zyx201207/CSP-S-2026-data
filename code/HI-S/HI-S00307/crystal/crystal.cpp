#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 500050;

int a[N], s[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	} 
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = l + r >> 1;
			int cha = (i - mid + 1) * a[i] - (s[i] - s[mid - 1]);
//			printf("mid = %d i = %d cha=%d\n", mid, i, cha);
			if (cha <= m) r = mid - 1;
			else l = mid + 1;
		}
//		printf("l = %d\n", l);
		ans = max(ans, i - l + 1);
	}
	printf("%lld\n", ans);
	return 0;
}
