#include<bits/stdc++.h>
#define LL long long
#define PII pair <LL, LL>
using namespace std;
bool bbb;
const LL N = 5e5 + 5, M = 505;
LL n, m, d, q;
LL w[N], dis[M][M];
vector <PII> v[N];
bool eee;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cerr << abs(&bbb - &eee) / 1024.0 / 1024 << '\n';
	cin >> n >> n >> m >> d >> q;
	for(LL i = 1; i <= m; i ++ ) cin >> w[i];
	for(LL i = 1, k; i <= n; i ++ ) {
		cin >> k;
		for(LL j = 1, p, t; j <= k; j ++ ) {
			cin >> p >> t;
			v[p].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(LL i = 1; i <= n; i ++ ) dis[i][i] = 0;
	for(LL i = 1; i <= m; i ++ ) {
		for(PII j : v[i]) for(PII k : v[i]) dis[j.first][k.first] = min(dis[j.first][k.first], j.second + k.second);
	}
	for(LL k = 1; k <= n; k ++ ) {
		for(LL i = 1; i <= n; i ++ ) {
			for(LL j = 1; j <= n; j ++ )
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
	for(LL i = 1, x, y; i <= q; i ++ ) {
		cin >> x >> y;
		LL res = 1e18;
		for(PII j : v[x]) for(PII k : v[y]) res = min(res, j.second + dis[j.first][k.first] + k.second);
		cout << res + w[x] + w[y] << '\n';
	}
	return 0;
}

