#include<bits/stdc++.h>
using namespace std;
/*
guanzhu _Liyx_ miao
AC at ?:?
*/
#define int long long
#define N 200005
int n, a[N], now, ans;
char c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	now = n;
	for (int i = 1; i <= n; i++) {
		for (; now > i && a[i]; now--) {
			if (a[now] > a[i]) {
				a[now] -= a[i];
				if (c[i] != c[now]) ans += a[i];
				a[i] = 0;
				break;
			}
			a[i] -= a[now];
			if (c[i] != c[now]) ans += a[now];
		}
		if (now == i) {
			break;
		}
	}
	cout << ans;
	return 0;
}
