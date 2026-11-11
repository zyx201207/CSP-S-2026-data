#include <bits/stdc++.h>
#define int long long

int N, M, a[500010];

bool check(int cnt) {
	int mn = 0x3f3f3f3f, now = 0;
	for (int i = 2; i <= cnt; i ++) now += (a[i] - a[i - 1]) * (i - 1);
	mn = std::min(mn, now);
	for (int i = cnt + 1; i <= N; i ++) {
		now += (a[i] - a[i - 1]) * cnt - a[i] + a[i - cnt];
		mn = std::min(now, mn);
	}
	
	return mn <= M;
}

signed main() {
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	std::cin >> N >> M;
	for (int i = 1; i <= N; i ++) std::cin >> a[i];
	std::sort(a + 1, a + N + 1);
	
	int l = 1, r = N, ans = 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	
	std::cout << ans;
	
	return 0;
} 
