#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;
int n, m, x, y, bcnt;
struct segment {
	int len;
	int st, ed;
	char c;
} a[N], f[N], b[N];
segment mid;
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].len >> a[i].c;
		a[i].st = m + 1;
		m += a[i].len;
		a[i].ed = m;
	}
	if (m & 1) {
		y = 1;
		mid = a[(m >> 1) + 1];
	}
	for (int i = 1; i <= n; i ++) {
		if (a[i].ed >= (m >> 1) && x == 0) {
			x = 1;
			f[i].ed = (m >> 1);
			break;
		}
	}
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
//	cin >> t;
	while (t --) {
		solve();
	}
	return 0;
}

