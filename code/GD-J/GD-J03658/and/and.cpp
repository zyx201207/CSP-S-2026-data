#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 2e4;
int n, m, a[N], ans = (1 << 30) - 1, ma = INT_MIN;
bool vis[N], flag = true, flag2 = true;
map<int, bool> v;

void dfs(int now, int ans, int cnt) {
	if (now == n + 1) {
		if (cnt == m) ma = max(ma, ans);
		return ;
	}
	dfs(now + 1, ans & a[now], cnt + 1);
	dfs(now + 1, ans, cnt);
}

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 30; i++) v[(1 << i) - 1] = true;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) if (v[a[i]] == false) flag = false;
	for (int i = 1; i <= n; i++) if (a[i] >= 4) flag2 = false;
	if (m == n) {
		for (int i = 1; i <= n; i++) ans = (ans & a[i]);
		cout << ans;
	}
	else if (m == 1) {
		for (int i = 1; i <= n; i++) ma = max(ma, a[i]);
		cout << ma;
	}
	else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue ;
				ma = max(ma, (a[i] & a[j]));
			}
		}
		cout << ma;
	}
	else if (flag == true) {
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= m; i++) ans = (ans & a[i]);
		cout << ans;
	}
	else if (flag2 == true) {
		sort(a + 1, a + 1 + n, cmp);
		int o = 0, t = 0, th = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) o++;
			else if (a[i] == 2) t++;
			else if (a[i] == 3) th++;
		}
		if (m <= th) ans = 3;
		else if (m <= t + th) ans = 2;
		else if (m <= o + th) ans = 1;
		else ans = 0;
		cout << ans;
	}
	else {
		dfs(1, ans, 0);
		cout << ma;
	}
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

10 6
2 3 1 2 3 1 2 3 2 3

43 25
1 3 7 4194303 15 31 63 127 255 511 1023 2047 32767 4095 8191 16383 16777215 32767 65535 65535 65535 65535 65535 131071 262143 16777215 524287 1048575 2097151 4194303 8388607 15 16777215 33554431 67108863 2047 134217727 262143 536870911 268435455 536870911 262143 1073741823
*/
