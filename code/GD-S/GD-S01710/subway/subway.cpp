#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int cc, n, m, d, q, dp [N][N];

int main(){
	memset (dp, 0x3f, sizeof (dp));
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);
	cin >> cc >> m >> n >> d >> q;
	vector <int> v (n + 1);
	for (int i = 1; i <= n; i++){
		cin >> v [i];
	}
	vector <int> c (m + 1);
	vector <vector <pair <int, int> > > g (m + 1);
	for (int i = 1; i <= m; i++){
		cin >> c [i];
		for (int j = 1; j <= c [i]; j++){
			int a1, t1;
			cin >> a1 >> t1;
			g [i].push_back ({a1, t1});
		}
	}
	for (int u = 1; u <= m; u++){
		for (auto p1 : g [u]){
			for (auto p2 : g [u]){
				if (p1 == p2){
					continue;
				}
				int u1 = p1.first, u2 = p1.second, v1 = p2.first, v2 = p2.second;
				dp [u1][v1] = min (dp [u1][v1], u2 + v2);
			}
		}
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dp [i][j] = min (dp [i][j], dp [i][k] + dp [k][j]);
			}
		}
	}
	for (int i = 1; i <= q; i++){
		int u, w;
		cin >> u >> w;
		cout << dp [u][w] + v [u] + v [w] << '\n';
	}
	return 0;
}
