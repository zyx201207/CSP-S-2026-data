#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 500;
constexpr int M = 5e5;
constexpr int K = 5e5;
constexpr int D = 20;

int c, n, m, d, q, w[M + 1], k, a[K + 1], t[K + 1], x, y;
int ce, head[M + 1], nxt[K + 1], to[K + 1], val[K + 1];
int cnt, cnt1, cnt2;
pair<int, int> tmp[D + 1], tmp1[D + 1], tmp2[D + 1];
ll dist[N + 1][N + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
			nxt[++ce] = head[a[j]];
			head[a[j]] = ce;
			to[ce] = i;
			val[ce] = t[j];
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = i == j ? 0 : LLONG_MAX;
	for (int i = 1; i <= m; i++) {
		cnt = 0;
		for (int j = head[i]; j; j = nxt[j])
			tmp[++cnt] = make_pair(to[j], val[j]);
		for (int ja = 1; ja <= cnt; ja++)
			for (int jb = 1; jb <= cnt; jb++) {
				auto ta = tmp[ja], tb = tmp[jb];
				dist[ta.first][tb.first] = min(dist[ta.first][tb.first], 0LL + ta.second + tb.second);
			}
	}
	for (int mid = 1; mid <= n; mid++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][mid] != LLONG_MAX && dist[mid][j] != LLONG_MAX)
					dist[i][j] = min(dist[i][j], dist[i][mid] + dist[mid][j]);
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		cnt1 = 0;
		for (int j = head[x]; j; j = nxt[j])
			tmp1[++cnt1] = make_pair(to[j], val[j]);
		cnt2 = 0;
		for (int j = head[y]; j; j = nxt[j])
			tmp2[++cnt2] = make_pair(to[j], val[j]);
		long long ans = LLONG_MAX;
		for (int ja = 1; ja <= cnt1; ja++)
			for (int jb = 1; jb <= cnt2; jb++) {
				auto ta = tmp1[ja], tb = tmp2[jb];
				if (dist[ta.first][tb.first] != LLONG_MAX)
					ans = min(ans, dist[ta.first][tb.first] + ta.second + tb.second + w[x] + w[y]);
			}
		cout << ans << '\n';
	}
	return 0;
}
