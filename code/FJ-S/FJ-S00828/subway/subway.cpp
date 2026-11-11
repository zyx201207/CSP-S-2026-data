#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL read() {
	
	LL x = 0;
	int f = 1;
	char ch = getchar();
	
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}	
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	
	return x * f;
}

void write(LL x) {
	
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + 48);
}

int c, n, m, d, q;

int r[500005];
LL G[505][505], f[505][505];

map< pair<int, int>, int > a, t;

vector< int > E[500005];

int main() {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i ++) {
		r[i] = read();
	}
	
	for (int i = 1; i <= n; i ++) {
		int k = read();
		for (int j = 1; j <= k; j ++) {
			int t1 = read(), t2 = read();
			E[t1].push_back(i);
			a[{i, j}] = t1, t[{i, t1}] = t2;
		}
	}
	
	for (int i = 1; i <= m; i ++) {
		for (int j : E[i]) {
			for (int k : E[i]) {
				if (j != k)
					G[j][k] = G[k][j] = t[{j, i}] + t[{k, i}];	
			}
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (!G[i][j] && i != j) {
				G[i][j] = 0x3f3f3f3f3f3f3f3f;
			}
			f[i][j] = G[i][j];
		}
	}
	
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (i != j)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	
	while (q --) {
		
		int x = read(), y = read();
		LL ans = 0x3f3f3f3f3f3f3f3f;
		
		for (int i : E[x]) {
			for (int j : E[y]) {
				if (t[{i, x}] + t[{j, y}] + f[i][j] < ans) {
					ans = t[{i, x}] + t[{j, y}] + f[i][j];
				}
			}
		}
		
		ans = ans + r[x] + r[y];

		write(ans); putchar('\n');
	}

	return 0;
} 

// wo yao ping xuan dian du chang shu zui da jiang (ye xiang shang qi pa da shang)
// ti mu you wen ti bian liang xie cuo le
