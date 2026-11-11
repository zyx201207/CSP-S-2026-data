

#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const int N = 510;
const int M = 500010;

int c;
int n;
int m;
int d;
int q;
long long post_time[M];
vector<pair<int, long long>> post_to_line[M];
long long line_dis[N][N];
long long res;

int main () {
	
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf ("%lld", &(post_time[i]));
	}
	for (int i = 1; i <= n; i++) {
		int len;
		scanf ("%d", &len);
		int a;
		long long t;
		for (int j = 1; j <= len; j++) {
			scanf ("%d%lld", &a, &t);
			post_to_line[a].emplace_back(i, t);
		}
	}
	
	memset (line_dis, 0x3f, sizeof (line_dis));
	for (int i = 1; i <= n; i++) {
		line_dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < post_to_line[i].size(); j++) {
			auto line1 = post_to_line[i][j];
			for (int k = 0; k < post_to_line[i].size(); k++) {
				auto line2 = post_to_line[i][k];
				line_dis[line1.first][line2.first] = min (line_dis[line1.first][line2.first], line1.second + line2.second);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				line_dis[i][j] = min (line_dis[i][j], line_dis[i][k] + line_dis[k][j]);
			}
		}
	}
	
	int x, y;
	for (int i = 1; i <= q; i++) {
		scanf ("%d%d", &x, &y);
		
		res = line_dis[0][0];
		for (int j = 0; j < post_to_line[x].size(); j++) {
			auto u = post_to_line[x][j];
			for (int k = 0; k < post_to_line[y].size(); k++) {
				auto v = post_to_line[y][k];
				res = min (res, line_dis[u.first][v.first] + u.second + v.second);
			}
		}
		res += post_time[x];
		res += post_time[y];
		
		printf ("%lld\n", res);
	}
	
	return 0;
}