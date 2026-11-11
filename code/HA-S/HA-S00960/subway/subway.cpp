#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int maxm = 5e3 + 10;

int c, n, m, d, p;

int w[maxm];

int k;

int a[maxm], t[maxm];

int f[maxm][maxm];

int main() {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	c = read(), n = read(), m = read(), d = read(), p = read();
	memset(f, 0x3f3f3f, sizeof(f));
	for(int i = 1; i <= m; i++) {
		w[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		k = read();
		for(int j = 1; j <= 2; j++) {
			a[j] = read(), t[j] = read();
		}
		f[a[1]][a[2]] = min(f[a[1]][a[2]], t[1] + t[2]);
		f[a[2]][a[1]] = min(f[a[2]][a[1]], t[1] + t[2]);
	}
	
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= m; j++) {
			for(int k = 1; k <= m; k++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	
	while(p--) {
		int x, y;
		x = read(), y = read();
		cout << f[x][y] + w[x] + w[y]<< "\n";
	}
	
	return 0;
}
