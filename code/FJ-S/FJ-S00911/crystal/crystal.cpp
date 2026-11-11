#include <bits/stdc++.h>
#define int long long

constexpr int N = 5e5 + 5;

int n, m, a[N], pre[N];

int Get (int i, int add) {
	return pre[i] + i * add;
}

int Binary (int x, int add, int i) {
//	std :: cout << '\n' << add << '\n';
//	std :: cout << i << '\n';
	int l = 0, r = i, mid;
	while (l < r) {
		mid = l + r >> 1;
//		std :: cout << l << r << mid << ' ' << Get (mid, add) << ' ';
		if (Get (mid, add) >= x) r = mid;
		else l = mid + 1;
	}
//	std :: cout << '\n';
	return r;
}

void solve () {
	std :: cin >> n >> m;
	for (int i = 1; i <= n; i ++) std :: cin >> a[i];
	std :: sort (a + 1, a + 1 + n);
	int x = a[1];
	for (int i = n; i; i --) a[i] = x - a[i];
	for (int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i];
	int ans = 0;
//	for (int i = 1; i <= n; i ++) std :: cout << pre[i] << ' ';
//	std :: cout << '\n';
	for (int i = 1; i <= n; i ++) {
		int t = -a[i];
		int k = Binary (pre[i] + t * i - m, t, i);
//		std :: cout << i << ' ' << k << ' ' << x << '\n';
		ans = std :: max (i - k, ans);
	}
	std :: cout << ans;
}

/*
5 5
1 2 4 8 9
*/

signed main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
//	int TTT; std :: cin >> TTT; while (TTT --)
	solve ();
	
	return 0;
}
