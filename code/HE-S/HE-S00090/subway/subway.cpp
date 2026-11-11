#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
long long w[500010];
vector <pair<int, int> > e[500010];
long long a[510][510];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)cin >> w[i];
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		while(k--){
			int a, t;
			cin >> a >> t;
			e[a].push_back({i, t});
		}
	}
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++)a[i][i] = 0;
	for (int i = 1; i <= m; i++){
		for (auto x : e[i]){
			for (auto y : e[i]){
				int u = x.first, v = y.first;
				if (u == v)continue;
				if (a[u][v] > x.second + y.second)a[u][v] = a[v][u] = x.second + y.second;
			}
		}
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			if (i == k)continue;
			for (int j = 1; j <= n; j++){
				if (j == k || j == i)continue;
				if (a[i][j] > a[i][k] + a[k][j])a[i][j] = a[i][k] + a[k][j];
			}
		}
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		long long ans = 0x7fffffffffffffff;
		for (auto i : e[x]){
			for (auto j : e[y]){
				if (ans > i.second + j.second + a[i.first][j.first])ans = i.second + j.second + a[i.first][j.first];
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
