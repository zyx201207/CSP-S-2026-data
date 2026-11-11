#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e6 + 10;

ll pos[N];
int nxt[N];
int sm[N], nm[N];

void solve () {
	int n, d, ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) {
		cin >> pos[i];
	}
	for (int i = 1; i <= n; i ++) {
		nxt[i] = upper_bound (pos + 1, pos + 1 + n, pos[i] + d) - pos;
		if (pos[i] + d < pos[nxt[i]]) nxt[i] --;
//		cout << nxt[i] << ' ';
	}
//	cout << '\n';
	for (int i = 1; i < n; i ++) {
		for (int j = 1; j <= n; j ++) sm[j] = 0, nm[j] = 0;
		int r = nxt[i], l = i + 1, res = 1;
		while (r <= n) {
			sm[l] = res;
			l ++;
			if (l > r) r = nxt[r + 1], res ++;
		}
		for (int j = n; !sm[j] && j >= 0; j --) sm[j] = res;
//		for (int j = 1; j <= n; j ++) cout << sm[j] << ' ';
//		cout << '\n';
		for (int j = i + 1; j <= n; j ++) {
			for (int l = j + 1; l <= nxt[j] && l <= n; l ++) {
				if (sm[j] + 1 == sm[l]) nm[l] ++; 
			}
		}
		for (int j = 1; j <= n; j ++) {
			if (nm[j] == 2) {
//				cout << i << ' ' << j << '\n';
				ans ++;
			}
		}
	}
	cout << ans << '\n';
}

signed main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	int c, t;
	cin >> c >> t;
	while (t --) {
		solve ();
	}
	return 0;
}
