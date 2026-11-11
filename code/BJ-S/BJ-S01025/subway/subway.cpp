#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5, M = 505;
int c, n, m, d, q, head[M], tot, w[N];
ll dis[M][M];
struct node {int x, y;};
vector<node> id[N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1, k, x, y; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> x >> y;
			for (node l : id[x]) dis[i][l.x] = dis[l.x][i] = min(dis[i][l.x], 1ll * l.y + y);
			id[x].push_back({i, y});
		}
	}
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1, x, y; i <= q; i++) {
		cin >> x >> y; ll ans = 1e18;
		for (node l1 : id[x])
			for (node l2 : id[y])
				ans = min(ans, l1.y + l2.y + dis[l1.x][l2.x]);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}