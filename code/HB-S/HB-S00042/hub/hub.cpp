#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int c, T, n, k, p[N], d[N], g[1010][1010], ans;
bool b[N];
vector<int> edges[N];

inline void solve(int x){
	b[x] = true;
	for (auto y : edges[x])
		if (!b[y])
			solve(y);
}

inline void solvee(int x){
	for (auto y : edges[x])
		if (d[y] == -1)
			d[y] = d[x] + 1, solvee(y);
}

inline void solveee(int x, int root){
	for (auto y : edges[x])
		if (g[root][y] == -1)
			g[root][y] = g[root][x] + 1, solveee(y, root);
}

inline void dfs(int i, int sum){
	if (i == n + 1){
		int res = 0;
		for (int j = 1; j <= n; j++)
			b[j] = false;
		for (int j = 1; j <= n; j++)
			if (p[j] && !b[j]){
				solve(j), ++res;
				if (res > 2)
					return;
			}
		int Max = 0;
		for (int j = 1; j <= n; j++)
			if (!p[j]){
				for (int i = 1; i <= n; i++)
					d[i] = -1;
				d[j] = 0;
				solvee(j);
				int Min = 1 << 30;
				for (int k = 1; k <= n; k++)
					if (p[k])
						Min = min(Min, d[k]);
				Max = max(Max, Min);
			}
		ans = min(ans, Max);
		return;
	}
	if (sum < k)
		p[i] = 1, dfs(i + 1, sum + 1);
	if (n - i >= k - sum)
		p[i] = 0, dfs(i + 1, sum);
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--){
		scanf("%d%d", &n, &k);
		for (int i = 1; i < n; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		ans = 1 << 30;
		if (c <= 3)
			dfs(1, 0);
		else{
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					g[i][j] = -1;
			for (int i = 1; i <= n; i++)
				g[i][i] = 0, solveee(i, i);
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++){
					int Max = 0;
					for (int l = 1; l <= n; l++)
						Max = max(Max, min(g[i][l], g[j][l]));
					ans = min(ans, Max);
				}
		}
		printf("%d\n", ans);
	}
	return 0;
}