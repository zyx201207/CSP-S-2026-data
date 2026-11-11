#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, M = 500005;
int d[N][N], w[M], n, m, c, D, q;
vector <int> a[M], t[M];
void chm(int x, int y, int w){ d[y][x] = d[x][y] = min(d[x][y], w);}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> D >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, k; i <= n; i++){
		cin >> k; int x, y;
		while(k--) cin >> x >> y, a[x].push_back(i), t[x].push_back(y);
	}
	memset(d, 0x3f, sizeof d);
	for(int i = 1; i <= n; i++) d[i][i] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = 0; j < a[i].size(); j++)
			for(int k = j + 1; k < a[i].size(); k++)
				chm(a[i][j], a[i][k], t[i][j] + t[i][k]);
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	while(q--){
		int x, y, ans = 2e18; cin >> x >> y;
		for(int i = 0; i < a[x].size(); i++)
			for(int j = 0; j < a[y].size(); j++)
				ans = min(ans, w[x] + w[y] + t[x][i] + t[y][j] + d[a[x][i]][a[y][j]]);
		cout << ans << '\n';
	}
	return 0;
}
