#include <bits/stdc++.h>
#define int long long
#define N (int)(5e3 + 5)
#define INF (long long)1e18
using namespace std;
int n, d;
int vis[N], a[N], ans[N][N], dis[N][N], ANS;
vector <int> e[N];
queue <int> q, st;
inline void Bfs (int s) {
	for (int i = 1; i <= n; i ++)
		vis[i] = 0;
	q.push (s), st.push (0);
	while (!q.empty ()) {
		int u = q.front (), step = st.front ();
		q.pop (), st.pop ();
		if (step < dis[s][u])
			ans[s][u] = 1, dis[s][u] = step;
		else if (step == dis[s][u])
			ans[s][u] ++;
		if (vis[u] == 1)
			continue ;
		vis[u] = 1;
		for (int i = 0; i < e[u].size (); i ++)
			q.push (e[u][i]), st.push (step + 1);
	}
}
inline void solve () {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++)
		e[i].clear ();
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; a[j] - d <= a[i] && j <= n; j ++)
			e[i].push_back (j);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			dis[i][j] = INF, ans[i][j] = 0;
	for (int i = 1; i <= n; i ++)
		Bfs (i);
	ANS = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			if (ans[i][j] == 2)
				ANS ++;
	cout << ANS << '\n';
}
int C, T;
signed main () {
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> C >> T;
	while (T --)
		solve ();
	return 0;
}
