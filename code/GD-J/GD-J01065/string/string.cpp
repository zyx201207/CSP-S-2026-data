#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define endl '\n'

using namespace std;

const int N = 2e5 + 5;
int n, a[N], len = 0;
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		if (i > 1 && c[i] != c[i - 1]) flag = false;
		len += a[i];
	}
	if (flag) {cout << 0; return 0;}
//	if (n & 1) {
		int ans = 0, i, j;
		int tmpl = a[1], tmpr = a[n];
		int reml = 0, remr = 0;
		char remlc = ' ', remrc = ' ';
		for (i = 1, j = n; i < j; ) {
//			cout << tmpl << ' ' << tmpr << ' ' << reml << ' ' << remlc << ' ' << remr << ' ' << remrc << endl;
			if (tmpl == tmpr) {
				ans += (c[i] == c[j] ? 0 : a[i]);
				reml = 0, remr = 0;
				i++, j--;
				tmpl += a[i], tmpr += a[j];
			} else if (tmpl > tmpr) {
				if (remrc != c[i]) ans += remr, remr = 0, remrc = ' ';
				reml = tmpl - tmpr;
				remlc = c[i];
				j--, tmpr += a[j];
			} else if (tmpr > tmpl) {
				ans += (remlc != c[j] ? a[j] - reml : 0);
				if (remlc != c[j]) ans += reml, reml = 0, remlc = ' ';
				remr = tmpr - tmpl;
				remrc = c[j];
				i++, tmpl += a[i];
			}
		}
		cout << ans << endl;
//	}
	return 0;
}
