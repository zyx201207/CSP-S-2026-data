#include<cstdio>
#include<cstring>
#include<vector>
int constexpr N = 500 + 1, M = 5e5 + 1;
int c, n, m, d, q;
long long dis[N][N], w[M], v[N][N];
struct Station {
	int s;
	long long t;
};
void link(int a, int b, long long val) {
	if(v[a][b] <= 0 || v[a][b] > val) {
		v[a][b] = v[b][a] = val;
	}
	return;
}
long long min(long long a, long long b) {
	return a < b ? a : b;
}
std::vector<Station> t[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m;i++) {
		scanf("%lld", &w[i]);
	}
	int k, ak;
	long long tk;
	memset(v, -1, sizeof v);
	for(int i = 1;i <= n;i++) {
		v[i][i] = 0;
		scanf("%d", &k);
		for(int j = 1;j <= k;j++) {
			scanf("%d%lld", &ak, &tk);
			t[ak].push_back({i, tk});
		}
	}
	for(int i = 1;i <= m;i++) {
		for(int j = 0;j != t[i].size();j++) {
			for(int k = j + 1;k < t[i].size();k++) {
				link(t[i][j].s, t[i][k].s, t[i][j].t + t[i][k].t);
				//printf("%d, %d\n", t[i][j].s, t[i][k].s);
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			dis[i][j] = v[i][j] < 0 ? 0x1f1f1f1f1f1f1f1f : v[i][j];
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			for(int k = 1;k <= n;k++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				//printf("%d, %d, %d: %lld\n", i, j, k, dis[i][j]);
			}
		}
	}
	int x, y;
	long long mi;
	for(int k = 1;k <= q;k++) {
		scanf("%d%d", &x, &y);
		mi = 0x1f1f1f1f1f1f1f1f;
		for(int i = 0;i != t[x].size();i++) {
			for(int j = 0;j != t[y].size();j++) {
				//1, x - sub[i] -> + w[x] + i.t
				//2, sub[i] - sub[j] -> + dis[i][j]
				//3, sub[j] - y -> j.t + w[y]
				mi = min(mi, dis[t[x][i].s][t[y][j].s] + w[x] + t[x][i].t + t[y][j].t + w[y]);
			}
		}
		printf("%lld\n", mi);
	}
	return 0;
}
