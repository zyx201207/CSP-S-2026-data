#include <bits/stdc++.h>
using namespace std;

struct node {	
	int line;
	bool st;
};

struct S {
	int station, time;
};

const int MAXN = 5E5+5;
int c, n, m, d, q;
vector<vector<int>> sta;
int ts[505][MAXN];
vector<vector<int>> grid;
vector<vector<int>> grids;
vector<vector<int>>	line;
int w[MAXN];
int ans= 0x3f3f3f3f;

void build () {
	for (int i = 1; i <= n; i ++) {
		int len = sta[i].size();
		int prev = -1;
		for (int j = 0; j < len; j ++) {
			if (prev == -1) {
				prev = sta[i][j];
				grid[sta[i][j]].push_back(i);
				continue;
			}
			grid[sta[i][j]].push_back(i);
			grids[prev].push_back(sta[i][j]);
			grids[sta[i][j]].push_back(prev);
		}
	}
	return ;
}

int bfs (int st, int tar) {
	queue<S> que;
	bool visited[MAXN];
	que.push({st, 0});
	while (!que.empty()) {
		int nows = que.front().station, nowt = que.front().time;
		que.pop();
		if (visited[nows])    continue;
		if (nows == tar) {
			return nowt;
		}
		visited[nows] = true;
		
		for (auto edge : grids[nows]) {
			int pt = nowt;
			pt += ts[grid[nows][edge].line][edge] + ts[grids[nows][edge].line][edge];
		}
	}
	return -1;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	sta.resize(n+5);
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++) {
			int a, t;
			cin >> a >> t;
			sta[i].push_back(a);
			ts[i][a] = t;
		}
	}
	build ();
	for (int i = ; i <= q; i ++) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + bfs(x, y) + w[y] << endl;
	}
	return 0;
} //อ๊มห 

