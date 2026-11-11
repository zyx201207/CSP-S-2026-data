//GZ-S00165 遵义市第四中学 杨子腾 
#include<bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e5 + 5;
#define ll long long
int w[M];
ll f[N][N];
vector<pair<int, int> > e[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q, memset(f, 63, sizeof(f));
	for (int i = 1;i <= m;i++)cin >> w[i];
	for (int i = 1;i <= n;i++)f[i][i] = 0;
	for (int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		while (k--) {
			int a, t;
			cin >> a >> t;
			for (auto& j : e[a])f[i][j.first] = f[j.first][i] = min(f[i][j.first], 0ll + t + j.second);
			e[a].push_back({i, t});
		}
	}
	for (int k = 1;k <= n;k++)for (int i = 1;i <= n;i++)for (int j = 1;j <= n;j++)
		f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--) {
		int x, y;
		ll ans = 1ll << 60;
		cin >> x >> y;
		for (auto& i : e[x])for (auto& j : e[y])ans = min(ans, i.second + j.second + f[i.first][j.first]);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
