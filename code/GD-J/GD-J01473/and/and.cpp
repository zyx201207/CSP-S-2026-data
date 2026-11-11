#include <bits/stdc++.h>
using namespace std;
#define int long long
#define up(i, a, b) for(int i = a; i <= b; i++)
#define dn(i, a, b) for(int i = a; i >= b; i--)
#define VI vector <int>
const int b30 = 1073741823;
int ans = -b30, n;
VI a;
void dfs(int d, int lim, int res) {
	if (lim == 0) {
		//cout << path << ' ' << res << endl;
		ans = max(ans, res);
		return;
	}
	if (d == n + 1)  {
		return;
	}
	dfs(d + 1, lim, res);
	dfs(d + 1, lim - 1, (res & a[d]));
	return;
}
void sub1() {
	int m; cin >> m;
	a.resize(n + 1);
	up (i, 1, n) cin >> a[i];
	dfs(1, m, b30);
	cout << ans;
}
void sub2() {
	int m; cin >> m;
	VI a(n + 1);
	up (i, 1, n) cin >> a[i];
	if (m == 1) {
		up (i, 1, n) ans = max(ans, a[i]);
		cout << ans;
		return;
	}
	if (m == 2) {
		up (i, 1, n) 
			up (j, i + 1, n) 
				ans = max (ans, a[i] & a[j]);
		cout << ans;
		return;
	}
	if (m == n) {
		ans = b30;
		up (i, 1, n) ans &= a[i];
		cout << ans;
		return;
	}
}
void sub3(int m) {
	VI a(n + 1);
	up (i, 1, n) cin >> a[i];
	VI pre(n + 1, b30), suf(n + 2, b30);
	up (i, 1, n) pre[i] = (pre[i - 1] & a[i]);
	dn (i, n, 1) suf[i] = (suf[i + 1] & a[i]);
	up (i, 1, n) {
		ans = max(ans, (pre[i - 1] & suf[i + 1]));
	}
	cout << ans;
	return;
}
void sub4(int m) {
	VI a(n + 1);
	up (i, 1, n) cin >> a[i];
	VI bi(33);
	up (i, 1, n) {
		int cnt = 0, x = a[i];
		while (x) {
			if (x % 2) bi[cnt]++;
			x /= 2;
			cnt++;
		}
	}
	up (i, 1, (1 << 24)) {
		bool f = 1;
		int cnt = 0, x = i;
		while (x > 0) {
			//cout << 1;
			if (x % 2) {
				if (bi[cnt] >= m) ;
				else {
					f = 0;
					break;
				}
			}
			x /= 2; cnt++;
		}
		if (f) ans = max(ans, i);
	}
	cout << ans;
	return;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n;
	if (n <= 20) sub1();
	else if (n <= 2000) sub2();
	else {
		int m; cin >> m;
		if (m == n - 1) sub3(m);
		else {
			sub4(m);
		}
	}
	return 0;
}

