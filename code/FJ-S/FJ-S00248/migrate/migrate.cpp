#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 5010;
int n, d, x[N], cnt[N], dis[N][N]; vector<int> g[N];
inline void add(int u, int v) { g[u].push_back(v), dis[u][v] = dis[v][u] = 1; }
inline void dfs(int x, int fa, int step)
{
	if (dis[x][fa] == step) cnt[x]++;
	for (int i = x + 1; i <= n; i++) if (dis[x][i] == inf) continue; else dfs(i, x, step + 1);
}
inline void solve()
{
	cin >> n >> d; for (int i = 1; i <= n; i++) cin >> x[i];
	int ans = 0; memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) { dis[i][i] = 0; for (int j = i + 1; j <= n; j++) if (x[j] - x[i] > d) break; else add(i, j); }
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= n; i++)
	{
		memset(cnt, 0, sizeof cnt);
		for (int j = i + 1; j <= n; j++) for (int k = i + 1; k < j; k++) if (dis[i][j] == dis[i][k] + dis[k][j]) cnt[j]++;
		for (int j = 1; j <= n; j++) if (cnt[j] == 2) ans++;
	}
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T; cin >> C >> T; while (T--) solve();
	return 0;
}
