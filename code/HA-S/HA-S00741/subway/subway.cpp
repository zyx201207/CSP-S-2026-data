#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
#define N 500005
#define M 505
#define inf 0x3f3f3f3f3f3f3f3f

ll c, n, m, d, q, w[N], l[N], f[M][M];
vector<ll> a[M], t[M];
vector<pii> v[N];

void solution(ll tas) {
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n) {
		cin >> l[i];
		rep(j, 1, l[i]) {
			ll x, w; cin >> x >> w;
			a[i].pb(x), t[i].pb(w), v[x].pb({i, w});
		}
	}
	rep(i, 1, n) rep(j, 1, n) f[i][j] = (i == j ? 0 : inf);
	rep(i, 1, m) rep(j, 0, (ll)v[i].size() - 2) 
		rep(k, j + 1, (ll)v[i].size() - 1) {
			pii t1 = v[i][j], t2 = v[i][k];
			ll x = t1.fi, y = t2.fi, w = t1.se + t2.se;
			f[x][y] = f[y][x] = min(f[x][y], w);
		}
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n)
		f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	//cout << f[1][2] << "\n";
	while(q --) {
		ll x, y, res = inf; cin >> x >> y;
		for(auto t1 : v[x]) for(auto t2 : v[y])
			res = min(res, f[t1.fi][t2.fi] + t1.se + t2.se);
		res += w[x] + w[y];
		cout << res << "\n";
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tas = 1; // cin >> tas;
	rep(i, 1, tas) solution(i);
	return 0;
}

/*
14:46 开题
14:55 m 怎么这么大，感觉是非常规做法，先去把 CD 的题面看一下
15:09 好像会了？这个 d 很关键
15:31 数组开太大了，改成 vector 才行
15:34 过大样例了 
*/
