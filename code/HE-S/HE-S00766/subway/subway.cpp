#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10;
const int N = 5e3 + 10;

struct Node {
  int to;
  int w;
};

vector<Node> adj[N + M];
unordered_map<int, int> path[N + M];
int w[M];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);

  int c, n, m, d, q;
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) {
    cin >> w[i];
  }
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int a, t;
      cin >> a >> t;
      adj[m + i + 1].push_back({a, t});
      adj[a].push_back({m + i + 1, t}); // m + i + 1 is subway line, a is station
      // so there is a total of n + m points
      path[m + i + 1][a] = path[a][m + i + 1] = t;
    }
  }

  // flyod
  for (int k = 1; k <= n + m; k++) {
    for (int i = 1; i <= n + m; i++) {
      for (int j = i + 1; j <= n + m; j++) {
	if (path[i][k] && path[k][j]) {
	  if (path[i][k] + path[k][j] < path[i][j] || !path[i][j]) {
	    path[i][j] = path[j][i] = path[i][k] + path[k][j];
	  }
	}
      }
    }
  }

  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << path[x][y] + w[x] + w[y] << endl;
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}
