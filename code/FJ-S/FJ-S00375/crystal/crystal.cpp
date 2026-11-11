#include <bits/stdc++.h>

#define int long long

const int N = 5e5 + 7;

int a[N], s[N];
int n, m;

bool check(int Mid) {
	for (int l = 1, r = Mid; r <= n; l ++, r ++) {
		if (s[r] - s[l - 1] + m >= a[r] * Mid) return 1;
	}
	return 0;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 

	scanf("%lld%lld", &n, &m); for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	int l = 1, r = n, ans = 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld", ans);
	
	return 0;
} 
