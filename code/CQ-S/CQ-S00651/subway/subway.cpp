#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector> 
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 510, M = 5e5 + 10;

int c, n, m, d, q;
ll w[M];
ll Map[N][N];

vector<pair<int, ll>> tai[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int ki;
		cin >> ki;
		for(int j = 1; j <= ki; j++) {
			int x, t;
			cin >> x >> t;
			tai[x].push_back({i, t});
		}
	}
	
	memset(Map, 0x3f, sizeof Map);
	for(int i = 1; i <= n; i++) Map[i][i] = 0;
	for(int i = 1; i <= m; i++) {
		int sz = tai[i].size();
		for(int j = 0; j < sz; j++) {
			for(int k = j + 1; k < sz; k++) {
				Map[tai[i][j].first][tai[i][k].first] = 
				min(Map[tai[i][j].first][tai[i][k].first],
				 tai[i][j].second + tai[i][k].second);
				 
				Map[tai[i][k].first][tai[i][j].first] = 
				min(Map[tai[i][k].first][tai[i][j].first],
				 tai[i][k].second + tai[i][j].second);
			}
		}
	}
	
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
			}
		}
	}
	
	while(q--) {
		int x, y;
		cin >> x >> y;
		int szx = tai[x].size(), szy = tai[y].size();
		ll res = 9e18;
		for(int i = 0; i < szx; i++) {
			for(int j = 0; j < szy; j++) {
				res = min(res, Map[tai[x][i].first][tai[y][j].first] + tai[x][i].second + tai[y][j].second + w[x] + w[y]);
			}
		}
		cout << res << endl;
	}
	
	return 0;
}
/* 
0 2 5 20 3
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
3 4
*/
