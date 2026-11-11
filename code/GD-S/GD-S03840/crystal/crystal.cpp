#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;

int n;
ll a[N], m;

bool check (int x) {
	int l = 1, r = x;
	ll sm = 0;
	for (int i = l; i < r; i ++) sm += a[r] - a[i];
	if (sm <= m) return true;
	for (; r <= n; l ++, r ++) {
		sm -= a[r - 1] - a[l - 1];
		sm += (a[r] - a[r - 1]) * (r - l);
		if (sm <= m) return true;
	}
	return false;
}

signed main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	int l = 0, r = n + 1;
	while (l + 1 < r) {
		int mid = l + r >> 1;
		if (check (mid)) l = mid;
		else r = mid;
	}
	cout << l << '\n';
	return 0;
}

/*
5 5
1 2 4 8 9
*/

/*
5 8
-3 -1 2 2 7
*/
