#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int a[N];
bool check (int x) {
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if ((x & a[i]) >= x) cnt ++;
	}
	return cnt >= m;
}
bool check1 (int x) {
	while (x %2 == 0) x >>= 1;
	return x == 1; 
}
void solve (int maxn) {
	for (int ans = maxn; ans >= 0; ans --) {
		if (check (ans)) {
			cout << ans;
			return;
		}
	}
}
void solve1 () {
	long long ans = a[1];
	for (int i = 2; i <= n; i ++) ans = (ans & a[i]);
	cout << ans;
}
void solve2 () {
	int maxn = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (i != j) {
				maxn = max (maxn, (a[i] & a[j]));
			}
		}
	}
	cout << maxn;
}
void solve3 () {
	int maxn = 0;
	for (int i = (1 << (m + 1)) - 1; i <= (i << (n - 1)); i ++) {
		int cnt = 0, ans = (1 << 21) - 1;
		for (int j = 0; j <= n; j ++) {
			if ((i >> j) & 1) {
				cnt ++;
				ans = ans & a[j];
			}
		}
		if (cnt >= m) maxn = max (maxn, ans);
	}
	cout << maxn;
}
void solve4 () {
	int ans = 0;
	for (int i = 0; i < m; i ++) {
		ans += (1 << i);
	}
	cout << ans;
}
int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout); 
	cin >> n >> m;
	int l = 0, r = 0, mid;
	bool ck = true;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		r = max (r, a[i]);
		if (!check1 (a[i] + 1)) ck = false;
	}
	if (r < 4) {
		solve (r);
		return 0;
	}
	if (m == 1) {
		cout << r;
		return 0;
	}
	if (n == m) {
		solve1 ();
		return 0;
	}
	if (m == 2) {
		solve2 ();
		return 0;
	}
	if (n <= 20) {
		solve3 ();
		return 0;
	}
	if (ck) {
		cout << "ck" << '\n';
		solve4 ();
		return 0;
	}
	while (r - l >= 5) {
		mid = l + (r - l) / 2;
		if (check (mid)) l = mid;
		else r = mid - 1;
	}
	for (int i = r; i >= l; i --) {
		if (check (i)) {
			cout << i;
			break;
		}
	}
	return 0; 
}
/*
test 1:

4 2 
3 15 12 12

test 2:

5 3
31 3 1 15 7

test 6:

5 5
1 2 3 4 5
*/
