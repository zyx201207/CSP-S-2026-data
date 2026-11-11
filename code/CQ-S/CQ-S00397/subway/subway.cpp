#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace Code {
	constexpr int N = 5e2 + 5;
	constexpr int M = 2e4 + 5;
	constexpr int Q = 1e5 + 5;
	constexpr int D = 2e1 + 5;

	struct Graph {
		int to, val;
		int line;
		
		Graph(int _to, int _val, int _line)
			: to(_to), val(_val), line(_line) {}
	};

	int c, n, m, d, q;
	int w[M], k[N];
	vector < int > a[N];
	vector < int > t[N];

	vector < Graph > G[M][N];

	unordered_map < int, unordered_map < int, int > > ans;

	class GraphTheory {
	private:
		struct Point {
			int dis;
			int point, line;

			Point(int _dis, int _point, int _line)
				: dis(_dis), point(_point), line(_line) {}

			bool operator < (const Point &other) const { return dis > other.dis; }
		};

		bool vis[M][N];
		priority_queue < Point > pq;

	public:
		int dis[M][N];

		void Dijkstra(int start) {
			memset(vis, 0, sizeof (vis));
			memset(dis, 0x7f, sizeof (dis));

			dis[start][0] = 0;
			pq.emplace(dis[start][0], start, 0);

			while (!pq.empty()) {
				auto cur = pq.top();
				pq.pop();

				if (vis[cur.point][cur.line]) continue;
				vis[cur.point][cur.line] = true;

				for (auto i : G[cur.point][cur.line]) {
					if (dis[i.to][i.line] > dis[cur.point][cur.line] + i.val) {
						dis[i.to][i.line] = dis[cur.point][cur.line] + i.val;
						pq.emplace(dis[i.to][i.line], i.to, i.line);
					}
				}
			}

			for (int i = 1; i <= m; ++ i) ans[start][i] = ans[i][start] = dis[i][0];
		}
	} graph;

	void main() {
		cin >> c >> n >> m >> d >> q;
		for (int i = 1; i <= m; ++ i) cin >> w[i];
		for (int i = 1; i <= n; ++ i) {
			cin >> k[i];
			for (int j = 1; j <= k[i]; ++ j) {
				int pos, val;
				cin >> pos >> val;

				a[i].emplace_back(pos);
				t[i].emplace_back(val);
			}
		}

		for (int i = 1; i <= m; ++ i) {
			G[i][0].emplace_back(i + m, w[i], 0);
			G[i + m][0].emplace_back(i, w[i], 0);
		}

		for (int i = 1; i <= n; ++ i) {
			for (int j = 0; j < k[i]; ++ j) {
				G[a[i][j] + m][0].emplace_back(a[i][j], t[i][j], i);
				G[a[i][j]][i].emplace_back(a[i][j] + m, t[i][j], 0);
			}
			for (int j = 0; j < k[i] - 1; ++ j) {
				G[a[i][j]][i].emplace_back(a[i][j + 1], 0, i);
				G[a[i][j + 1]][i].emplace_back(a[i][j], 0, i);
			}
		}

		while (q --) {
			int x, y;
			cin >> x >> y;

			if (!ans[x][y]) graph.Dijkstra(x);
			cout << ans[x][y] << '\n';
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Code::main();

	return 0;
}

/*
++ rp
*/