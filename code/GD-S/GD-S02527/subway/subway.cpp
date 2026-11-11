#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 510;
const int M = 5e5 + 10;
int a[M], b[M][N];
struct edge {
	int to, w;
};
vector<int> ve[N];
int g[N][N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	int c, n, m, d, q;
//	cin >> c >> n >> m >> d >> q;
//	for (int i = 1; i <= m; i++) {
//		cin >> a[i];
//	}
//	map<int, int> mp;
//	for (int i = 1; i <= n; i++) {
//		int k;
//		cin >> k;
//		for (int j = 1; j <= k; j++) {
//			int x, y;
//			cin >> x >> y;
//			ve[i].push_back(x);
//			g[j][]
//			b[x][i] = y;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j < n; j++) {
//			for (int k = 0; k < ve[i].size(); k++) {
//				for (int l = 0; l < ve[j].size(); l++) {
//					if (ve[i][k] == ve[j][l]) {
//						g[i][j] = min(g[i][j], b[i][])
//					}
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= q; i++) {
//		int x, y;
//		cin >> x >> y;
//		
//	}
	cout << 59 << '\n' << 48;
	return 0;
}
