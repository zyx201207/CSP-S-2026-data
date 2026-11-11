#include <bits/stdc++.h>
#define re read()
#define wr(x) write(x)
#define sp putchar(' ')
#define endl puts("")
#define int long long

const int N = 2e6 + 10, INF = 0x3f3f3f3f;

using namespace std;

int read() {
	int y = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') f = c == '-' ? -1 : f, c = getchar();
	while (c >= '0' && c <= '9') y = (y << 1) + (y << 3) + (c ^ 48), c = getchar();
	return y * f;
}

void write(int x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

int n, d;
int a[N], nxt[N];
int t, k;
int X = 0;

void dfs(int x, int cnt) {
	if (X > 2) return ;
	if (cnt > k) return ;
	if (x >= t) return X += cnt == k, void();
	for (int i = min(nxt[x], t); i > x; i--) {
		dfs(i, cnt + 1);
		if (X > 2) return ;
	}
}

void solve() {
	n = re, d = re;
	for (int i = 1; i <= n; i++) a[i] = re, nxt[i] = 0;
	for (int i = 1; i <= n; i++) for (int j = n; j >= i + 1; j--) if (a[j] - a[i] <= d) {
		nxt[i] = j;
		break;
	}
//	puts("NXT:");
//	for (int i = 1; i <= n; i++) wr(nxt[i]), sp;
//	endl;
	int ans = 0;
	for (int l = 1; l <= n; l++) for (int r = l + 1; r <= n; r++) {
		int x = l, cnt = 0;
		while (x < r) {
			x = nxt[x], cnt++;
			if (x == nxt[x]) break;
		}
		if (x == nxt[x]) break;
		t = r, k = cnt, X = 0;
		dfs(l, 0), ans += X == 2;
		if (X > 2) break;
	}
	wr(ans), endl;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int XXXXX = re, t = re;
	while (t--) solve();
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

