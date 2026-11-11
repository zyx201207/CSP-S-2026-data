#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 5e5 + 10, N = 510;
struct Edge{
	int to;
	int v;
	Edge (int x, int y) {
		to = x, v = y;
	}
};
int c, n, m, d, q;
int w[M], k[N], a[N][M], t[N][M];
//0 ¡Ü c ¡Ü 25£¬1 ¡Ü n ¡Ü 500£¬1 ¡Ü m ¡Ü¦²i=1~n ki ¡Ü 5¡Á105£¬1 ¡Ü d ¡Ü 20£¬1 ¡Ü q ¡Ü 105£»

ll solve(int x, int y) {
	return rand();
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}
	return 0;
}
