#include <bits/stdc++.h>
using namespace std;
int read() {
	int res = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		res = res * 10 + ch- '0';
		ch = getchar();
	}
	return res * f;
}

const int N = 505;
int w[N],a[N][N],t[N][N];
int c,n,m,d,q;

int main () {
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for (int i = 1;i <= m; ++i) w[i] = read();
	for (int i = 1;i <= n; ++i) {
		int k; k = read();
		for (int j = 1;j <= k; ++j) {
			a[i][j] = read();
			t[i][j] = read();
		}
	}
	while (q--) {
		
	}
	return 0;
}
