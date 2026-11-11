#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define deb(x) cerr << #x << ":" << x << " "
using namespace std;
const int N = 2e5 + 5;
int n, m, x, y, ans;
struct segment {
	int len;
	int st, ed;
	char c;
} a[N], f[N], b[N];
segment mid;
string s = " ";
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].len >> a[i].c;
		a[i].st = m + 1;
		m += a[i].len;
		a[i].ed = m;
	}
	if (n == 1) 
		cout << "0\n";
	else {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= a[i].len; j ++) {
				s += a[i].c;
			}
		}
//		cerr << s << "\n";
		for (int i = 1; i <= (m >> 1); i ++) {
			if (s[i] != s[m + 1 - i]) 
				ans ++;
//			deb(i), deb(s[i]), deb(m + 1 - i), deb(s[m + 1 - i]), deb(ans), cerr << "\n";
		}
		cout << ans << "\n";
	}
//	if (m & 1) {
//		y = 1;
//		mid = a[(m >> 1) + 1];
//	}
//	// get b[] and f[]
//	for (int i = 1; i <= n; i ++) {
//		f[i] = a[i];
//		if (a[i].ed >= m - (m >> 1)) {
//			f[i].ed = (m >> 1);
//			x = i;
//			break;
//		}
//	}
//	int j = 0;
//	for (int i = n; i; i --) {
//		b[++ j] = a[i];
//		swap(b[j].st, b[j].ed);
//		if (a[i].st <= (m >> 1)) {
//			b[j].ed = m - (m >> 1);
//			y = j;
//			break;
//		}
//	}
	// work
	// the hell of if :-(
//	for (int p1 = 1, p2 = 1, i = 1; ; i ++) {
//		segment A = f[p1], B = b[p2];
//		if (A.st == B.st) {
//			if (A.ed == B.ed) {
//				if (A.c != B.c)
//					ans += (A.ed - A.st + 1);
//				p1 ++;
//				p2 ++;
//			} else if (A.ed > B.ed) {
//				if (A.c != B.c)
//					ans += (B.ed - B.st + 1);
//				segment C;
//				int p = p2;
//				for (C = b[p]; A.ed >= C.ed; C = b[++ p]) {
//					if (A.c != B.c)
//					ans += (B.ed - B.st + 1);
//				}
//				p2 ++;
//			} else {
//				if (A.c != B.c) 
//					ans += (A.ed - A.st + 1);
//				p1 ++;
//			}
//		} 
//	}
//	// trying
//	for (int p1 = 1, p2 = 1; )
//	
//	
//	while (1) {
//		segment A = f[p1], B = b[p2];
//		if (A.st < B.st) {
//			ans += (A.c == B.c ? 0 : A.len);
//			while ()
//			ans += ()
//		}
//	}
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

