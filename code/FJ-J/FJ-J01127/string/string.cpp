#include <iostream>
#include <cctype>
#define gc getchar
#define pc putchar
#define int long long
using namespace std;
const int N = 200005;
int n, a[N], v[N], sum, len, l, r, cut, ans;
inline void rd(int &x) {
	int sum = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
	for (; isdigit(c); c = gc()) sum = sum * 10 + c - '0';
	x = sum * f;
}
inline void rdl(int &x) {
	int c = gc();
	for (; !islower(c); c = gc()) {}
	for (; islower(c); c = gc()) x = c - 'a' + 1;
}
inline void wt(int x) {
	if (x > 9) wt(x/10);
	pc(x%10+'0');
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	rd(n);
	for (int i = 1; i <= n; i++) {
		rd(a[i]); rdl(v[i]);
		sum += a[i];
	}
	len = sum >> 1;
	l = 1; r = n;
	for (int i = 1, j = sum; i <= len && i < j;) {
		if (l == r) break;
		cut = min(a[l], a[r]);
		i += cut, j -= cut;
		if (v[l] != v[r]) ans += cut;
		if (a[l] == a[r]) l++, r--;
		else if (a[l] < a[r]) l++, a[r] -= cut;
		else r--, a[l] -= cut;
	}
	wt(ans);
	return 0;
}
