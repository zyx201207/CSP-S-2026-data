#include <bits/stdc++.h>
using namespace std;
const int max_m = 500001, max_q = 100001;
const short int max_n = 501;
const signed char max_d = 21;
int w[max_m], k[max_n], x[max_q], y[max_q], sr[max_m];
vector<int> a[max_n], t[max_n];
long long int ans[max_q];
bool vis[max_m];
pair<int, int> r[max_m][max_d];
priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> que;
namespace my_namespace {
	int main() {
		freopen("subway.in", "r", stdin);
		freopen("subway.out", "w", stdout);
		int c, n, m, d, q;
		scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);

		for (int i = 1; i <= m; ++i) {
			scanf("%d", &w[i]);
		}

		for (int i = 1; i <= n; ++i) {
            a[i].push_back(0);
            t[i].push_back(0);
			scanf("%d", &k[i]);

			for (int j = 1; j <= k[i]; ++j) {
                int aa, tt;
				scanf("%d%d", &aa, &tt);
                a[i].push_back(aa);
                t[i].push_back(tt);
			}
		}

		for (int r = 1; r <= q; ++r) {
			scanf("%d%d", &x[r], &y[r]);
		}

		for (int i = 1; i <= n; ++i) {

			for (int j = 1; j <= k[i]; ++j) {
				r[a[i][j]][++sr[a[i][j]]] = make_pair(i, t[i][j]);
			}
		}

		for (int i = 1; i <= q; ++i) {
			ans[i] = w[x[i]];
			memset(vis, 0, sizeof(vis));

			while (!que.empty()) {
                que.pop();
			}

			que.push(make_pair(0, x[i]));

			while (!que.empty()) {
				long long int nx = que.top().first;
				int ny = que.top().second;
				que.pop();

				if (ny == y[i]) {
					ans[i] += nx;
					break;
				}

				if (vis[ny])
					continue;

				vis[ny] = 1;

				for (int j = 1; j <= sr[ny]; ++j) {

					for (int kk = 1; kk <= k[r[ny][j].first]; ++kk) {

						if (a[r[ny][j].first][kk] != ny)
							que.push(make_pair((long long int)nx + r[ny][j].second + t[r[ny][j].first][kk], a[r[ny][j].first][kk]));
					}
				}
			}

			ans[i] += w[y[i]];
		}

		for (int i = 1; i <= q; ++i) {
			printf("%lld\n", ans[i]);
		}

		return 0;
	}
}
int main() {
	return my_namespace::main();
}