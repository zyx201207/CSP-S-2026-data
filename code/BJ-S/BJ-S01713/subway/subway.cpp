#include <bits/stdc++.h>

#define _for(i, a, b) for (int i = (a); i <= (int)(b); i ++ )
#define fi first
#define se second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
const int N = 510, M = 5e5 + 10;
const LL INF = 1e18;
int C, n, m, D, q;
vector<PII> a[M];
LL d[N][N], w[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> C >> n >> m >> D >> q;
	_for (i, 1, m) cin >> w[i];
	_for (i, 1, n) {
		int k;
		cin >> k;
		while (k -- ) {
			int pt, ti;
			cin >> pt >> ti;
			a[pt].push_back({i, ti});
		}
	}
	memset(d, 0x3f, sizeof d);
	_for (i, 1, n) d[i][i] = 0;
	_for (i, 1, m) {
		_for (j, 0, (int)a[i].size() - 1) {
			_for (k, 0, (int)a[i].size() - 1) {
				PII x = a[i][j], y = a[i][k];
				d[x.fi][y.fi]=d[y.fi][x.fi]=min(d[x.fi][y.fi], (LL)x.se + y.se);
			}
		}
	}
	_for (k, 1, n)
		_for (i, 1, n)
			_for (j, 1, n)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	
	while (q -- ) {
		int st, ed;
		cin >> st >> ed;
		LL ans = w[st] + w[ed], res = INF;
		for (auto x : a[st])
			for (auto y : a[ed])
				res = min(res, (LL)x.se + y.se + d[x.fi][y.fi]);
		cout << ans + res << '\n';
	}
	return 0;
}
