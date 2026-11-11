#include <bits/stdc++.h>
#define int long long
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define rd read()
using namespace std;
const int N = 5 + 2e5;
int n, L, ans;
struct node {
	int len; char ch;
} a[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void write(int x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	n = rd;
	rep(i, 1, n) {
		L += a[i].len = rd;
		cin >> a[i].ch;	
	}
	int l = 1, r = n;
	while (l < r) {
		if (a[l].len == a[r].len) {
			if (a[l].ch != a[r].ch) ans += a[l].len;
			l++; r--;
		} else if (a[l].len < a[r].len) {
			if (a[l].ch != a[r].ch) ans += a[l].len;
			a[r].len -= a[l].len;
			l++;
		} else {
			if (a[l].ch != a[r].ch) ans += a[r].len;
			a[l].len -= a[r].len;
			r--;
		}
	}
	write(ans);
}
