#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 7, M = 2e7 + 5;
struct node {
	ll x; char c;
}a[N], b[N];
string s;
int n;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	s = "";
	ll len = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i].x >> b[i].c;
		len += b[i].x;
	}
//	if (len <= M) {
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= b[i].x; ++j) s += b[i].c;
//		}
//		s = ' ' + s;
////		cout << s << "\n";
//		int l = 1, r = s.size() - 1;
////		cout << l << ' ' << r << "\n";
//		ll ans = 0;
//		while (l < r) {
//			if (s[l] != s[r]) ans++;
//			l++, r--;
////			cout << l << ' ' << r;
//		}
//		cout << ans;
//		return 0;
//	}
	int idx = 0;
	for (int i = 1; i <= n; ++i) {
		int j = i;
		ll nx = b[i].x;
		while (j + 1 <= n && b[i].c == b[j + 1].c) {
			j++;
			nx += b[j].x;
		}
		a[++idx].x = nx, a[idx].c = b[i].c;
		i = j;
	}
//	for (int i = 1; i <= idx; ++i) cout << a[i].x << ' ' << a[i].c << "\n"; 
	int l = 1, r = idx;
	while (l < r) {
		if (a[l].x == a[r].x) {
			if (a[l].c != a[r].c) ans += a[l].x;
			l++, r--;
		}
		else {
			if (a[l].c != a[r].c) {
				if (a[l].x > a[r].x) {
					ans += a[r].x;
					a[l].x -= a[r].x;
					r--;
				}
				else {
					ans += a[l].x;
					a[r].x -= a[l].x;
					l++;
				}
			}
			else {
				if (a[l].x > a[r].x) {
					a[l].x -= a[r].x;
					r--;
				}
				else {
					a[r].x -= a[l].x;
					l++;
				}
			}
		}
	}
//	if (len % 2 != 0 && idx % 2 == 0) {
//		int i = n / 2, j = idx / 2 + 1;
////		cout << a[i].x << ' ' << a[j].x;
//		if (a[i].x != a[j].x) {
//			if (a[i].c == a[j].c) ans -= max(a[i].x, a[j].x) - min(a[i].x, a[j].x);
//			else {
//				ans -= max(a[i].x, a[j].x) - min(a[i].x, a[j].x);
//				ans += min(a[i].x, a[j].x);
//			}
//		}
////		else cout << "Oh!!";
//	}
	cout << ans;
	return 0;
}
/*
if (a[i].c == a[j].c) { // cnti != cntj but ci == cj
				if (a[i].x > a[j].x) {
					ans += a[i].x - a[j].x;
					if (a[i + 1].x < a[j - 1].x) {
						int t1 = a[i].x;
						a[i].x = a[j].x;
						a[i + 1].x += (t1 - a[j].x);
					}
					else {
						int t2 = a[j].x;
						a[j].x = a[i].x;
						a[j - 1].x += (t2 - a[j].x);
					}
				}
				else {
					ans += a[j].x - a[i].x;
					if (a[i + 1].x < a[j - 1].x) {
						int t1 = a[i].x;
						a[i].x = a[j].x;
						a[i + 1].x += (t1 - a[j].x);
					}
					else {
						int t2 = a[j].x;
						a[j].x = a[i].x;
						a[j - 1].x += (t2 - a[j].x);
					}
				}
			}
			else { // cnti != cntj and ci != cj
				if (a[i].x > a[j].x) {
					ans += a[i].x - a[j].x;
					if (a[i + 1].x < a[j - 1].x) {
						int t1 = a[i].x;
						a[i].x = a[j].x;
						a[i + 1].x += (t1 - a[j].x);
					}
					else {
						int t2 = a[j].x;
						a[j].x = a[i].x;
						a[j - 1].x += (t2 - a[j].x);
					}
				}
			}
*/
