#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const ll N = 505, M = 5e5 + 5, INF = 0x3f3f3f3f3f3f3f3f;
ll c, n, m, d, q, w[M], k[N], dis[N][N];
vector<ll> a[N], t[N], A[M], T[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	for (ll i = 1; i <= m; i++) scanf("%lld", w + i);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", k + i);
		for (ll j = 1, aa, tt; j <= k[i]; j++) {
			scanf("%lld %lld", &aa, &tt);
			a[i].push_back(aa);
			t[i].push_back(tt);
			A[aa].push_back(i);
			T[aa].push_back(tt);
		}
	}
	for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++) dis[i][j] = INF;
	for (ll i = 1; i <= n; i++) dis[i][i] = 0;
	for (ll i = 1; i <= m; i++) {
		for (ll j = 0; j < (ll)A[i].size(); j++)
			for (ll p = j + 1; p < (ll)A[i].size(); p++) {
				dis[A[i][j]][A[i][p]] = min(dis[A[i][j]][A[i][p]], T[i][j] + T[i][p]);
				dis[A[i][p]][A[i][j]] = min(dis[A[i][p]][A[i][j]], T[i][j] + T[i][p]);
			}
	}
	for (ll p = 1; p <= n; p++) for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][p] + dis[p][j]);
	
	ll x, y, ans;
	while (q--) {
		scanf("%lld %lld", &x, &y);
		ans = INF;
		for (ll i = 0; i < (ll)A[x].size(); i++)
			for (ll j = 0; j < (ll)A[y].size(); j++)
				ans = min(ans, dis[A[x][i]][A[y][j]] + T[x][i] + T[y][j] + w[x] + w[y]);
		printf("%lld\n", ans);
	}
	return 0;
}
