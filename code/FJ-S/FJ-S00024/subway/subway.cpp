#include <bits/stdc++.h>

const int N = 503, M = 500003;
const long long INF = 1000000000000000000;

//  ²â Ïß Õ¾ ×ª ÎÊ 
int c, n, m, d, q;
long long w[M], tot[M], a[M][23], t[M][23], pre[N][N];

void cmin(long long &x, long long y) {
	x = std::min(x, y);
}


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	std::cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) {
		std::cin >> w[i];
	}
	for(int i = 1; i <= n; ++i) {
		int k; std::cin >> k;
		for(int j = 1; j <= k; ++j) {
			long long x, y;
			std::cin >> x >> y;
			a[x][++tot[x]] = i;
			t[x][tot[x]] = y;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i != j) pre[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j < tot[i]; ++j) {
			for(int k = j+1; k <= tot[i]; ++k) {
				cmin(pre[a[i][j]][a[i][k]], t[i][j] + t[i][k]);
				cmin(pre[a[i][k]][a[i][j]], t[i][j] + t[i][k]);
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int k = 1; k <= n; ++k) {
				cmin(pre[j][k], pre[i][j] + pre[i][k]);
				cmin(pre[k][j], pre[i][j] + pre[i][k]);
			}
		}
	}
	while(q--) {
		int x, y;
		std::cin >> x >> y;
		long long res = INF;
		for(int i = 1; i <= tot[x]; ++i) {
			for(int j = 1; j <= tot[y]; ++j) {
				cmin(res, t[x][i] + t[y][j] + pre[a[x][i]][a[y][j]]);
			}
		}
		std::cout << res + w[x] + w[y] << '\n';
	}
	
	return 0;
}
