#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2000020;

int n, d, f[N], nxt[N], a[N], s[N], ss[N];

void solve() {
	for (int i = 1;  i <= n; i++) {
		s[i] = f[i] = ss[i] = 0;
	}
	scanf("%lld%lld", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]); 
	}
	for (int i = 1; i <= n; i++) {
		int l = i, r = n;
		while (l <= r) {
			int mid = l + r >> 1;
			if (a[mid] <= a[i] + d) l = mid + 1;
			else r = mid - 1; 
		} 
		nxt[i] = r;	
	}
	int ans = 0, lst = n;
	for (int i = n; i; i--) if (i != nxt[i]) {
		s[i] = s[nxt[i]] + nxt[i];
		ss[i] = ss[nxt[i]] + 1;
		f[i] = f[nxt[i]];
		if (nxt[i] - i > 1) f[i] += max(0LL, s[nxt[i] - 1] - s[i] + 
		(ss[nxt[i]] < ss[nxt[i] - 1] ? 0 : lst));
		ans += f[i];
//		printf("f[%d]=%d s[%d]=%d\n", i, f[i], i, s[i]);
	}else lst = i;
	printf("%lld\n", ans);
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T;
	scanf("%lld%lld", &C, &T);
	while (T--) solve();
	return 0;
}
