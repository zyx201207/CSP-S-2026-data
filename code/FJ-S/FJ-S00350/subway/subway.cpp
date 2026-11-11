#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int M = 5e5 + 5;
const int N = 505;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;
vector<pair<int, int> > z[M];
int t1[M], p;
long long dis[N][N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i)  cin >> t1[i];
	for(int i = 1; i <= n; ++i) {
		cin >> p;
		for(int j = 1; j <= p; ++j) {
			int x, y;
			cin >> x >> y;
			z[x].push_back({i, y});
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			dis[i][j] = INF;
			if(i == j) dis[i][j] = 0;
		}
	}
	for(int i = 1; i <= m; ++i) {
		for(auto u : z[i]) {
			for(auto v : z[i]) {
				int uz = u.first, vz = v.first;
				int ul = u.second, vl = v.second;
				if(uz == vz) continue;
				long long nw = ul + vl;
				dis[uz][vz] = min(dis[uz][vz], nw);
			}
		}
	}
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(dis[i][k] != INF && dis[k][j] != INF){
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		long long t = t1[x] + t1[y], ans = INF;
		for(auto u : z[x]) {
			for(auto v : z[y]) {
				int uz = u.first, vz = v.first;
				int ul = u.second, vl = v.second;
				long long na = t + dis[uz][vz] + ul + vl;
				ans = min(ans, na);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
