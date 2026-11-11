#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##KON = (r); i <= i##KON; ++i)
#define per(i, l, r) for(int i = (l), i##KON = (r); i >= i##KON; --i)
using namespace std;
using ll = long long;
constexpr ll N{500005}, inf{0x3f3f3f3f3f3f3f3f};
ll tid, n, m, D, q, w[N], a[N][22], t[N][22], c[N], d[505][505];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> tid >> n >> m >> D >> q;
	rep(i, 1, m)
		cin >> w[i];
	memset(d, 0x3f, sizeof(d));
	rep(i, 1, n)
	{
		ll k, u; cin >> k;
		d[i][i] = 0;
		rep(j, 1, k)
		{
			cin >> u;
			a[u][++c[u]] = i;
			cin >> t[u][c[u]];
		}
	}
	rep(i, 1, m) rep(x, 1, c[i]) rep(y, 1, c[i])
		d[a[i][x]][a[i][y]] = min(d[a[i][x]][a[i][y]], t[i][x] + t[i][y]);
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	rep(Q, 1, q)
	{
		ll l, r, ans = inf;
		cin >> l >> r;
		rep(i, 1, c[l]) rep(j, 1, c[r])
			ans = min(ans, d[a[l][i]][a[r][j]] + t[l][i] + t[r][j]);
		cout << ans + w[l] + w[r] << "\n";
	}
	return 0;
}