#include <bits/stdc++.h>
#define int long long
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define rd read()
using namespace std;
const int N = 5 + 5e5;
int n, m, a[N], stk[N], top, ans[N];
struct node {
	int pos, l, r;
};
vector<node> e[N];
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
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = rd; m = rd;
	rep(i, 1, n) a[i] = rd;
	bool chk = 1;
	rep(i, 2, n) {
		chk &= (a[i] >= a[i - 1]);
	}
	if (chk) {
		rep(i, 1, n) {
			if (a[i + 1] != a[i]) {
				write(i), putchar(' ');
			}
		}
		return 0;
	}
	rep(stt, 1, n) {
		vector<bool> vis(n + 5, false);
		top = 0;
		rep(i, stt, n) {
			if (vis[a[i]]) {
				while (stk[top] != a[i] && top > 0) {
					vis[stk[top--]] = 0;
				}
			}
			else {
				stk[++top] = a[i];
				vis[a[i]] = 1;
			}
		}
		rep(i, 1, top) ans[stk[i]]++;
	}
	rep(i, 1, m) write(ans[i]), putchar(' ');
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
