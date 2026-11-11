/*
难道就是个阅读题吗

题目读懂了，暴力是简单的，直接最短路可以做到qmlog

有44分

不难发现只有最后一步会有w的消耗

可以转化成给n个集合，集合若有公共点就可以建边

发现可以建立虚点 

完全不知道多少分

有点慌张了 
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int M = 5e5 + 1000, N = 510;
const ll inf = 1e18;

void Freopen() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
}

int c, n, m, d, q; 
ll w[M];

vector< ll> t[N];
vector< int> a[N], bl[M];

ll mp[N][N];
bool vis[M];
int rev[M];

ll ans[N][100100], mpp[N][100010];

int X[100010], Y[100010];
int ind[100100];
int Rev[M];

int ind2[100100], Revx[M];

signed main() {
	Freopen();
	
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for ( int i = 1; i <= m; i ++) cin >> w[i];
	for ( int i = 1; i <= n; i ++) {
		int k; cin >> k;
		
		while (k --) {
			int x; ll w;
			cin >> x >> w;
			a[i].push_back(x);
			bl[x].push_back(i);
			t[i].push_back(w);
		}
	}
	
	memset(ans, 127, sizeof ans);
	
	for ( int i = 0; i <= n; i ++)
		for ( int j = 0; j <= n; j ++)
			mp[i][j] = inf;
	
	for ( int i = 1; i <= n; i ++) {
		for ( int k = 0; k < (int)a[i].size(); k ++) {
			int v = a[i][k];
			vis[v] = 1, rev[v] = k;
		}
		
		mp[i][i] = 0;
		
		for ( int j = 1; j <= n; j ++) {
			if (i == j) continue ;
	
			for ( int k = 0; k < (int)a[j].size(); k ++) {
				int v = a[j][k];
				if (vis[v]) mp[i][j] = min(mp[i][j], t[i][rev[v]] + t[j][k]);
			}
		}
		
		for ( auto v : a[i]) vis[v] = 0;
	}
	
	for ( int k = 1; k <= n; k ++)
		for ( int i = 1; i <= n; i ++)
			for ( int j = 1; j <= n; j ++)
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
	
	for ( int i = 1; i <= q; i ++) {
		cin >> X[i] >> Y[i];
		ind[i] = Y[i], ind2[i] = X[i];
	}
	
	sort(ind + 1, ind + q + 1);
	sort(ind2 + 1, ind2 + q + 1);
	int tot = unique(ind + 1, ind + q + 1) - ind - 1;
	int tot2 = unique(ind2 + 1, ind2 + q + 1) - ind2 - 1;
	
	for ( int i = 1; i <= q; i ++) Rev[Y[i]] = lower_bound(ind + 1, ind + tot + 1, Y[i]) - ind;
	for ( int i = 1; i <= q; i ++) Revx[X[i]] = lower_bound(ind2 + 1, ind2 + tot2 + 1, X[i]) - ind2;
	
	for ( int i = 1; i <= n; i ++)
		for ( int j = 1; j <= n; j ++)
			for ( int k = 0; k < (int)a[j].size(); k ++) {
				int v = a[j][k];
				ans[i][Rev[v]] = min(ans[i][Rev[v]], mp[i][j] + t[j][k]);
			}
			
	for ( int i = 1; i <= n; i ++)
		for ( int k = 0; k < (int)t[i].size(); k ++) {
			int v = a[i][k];

			if (! Revx[v]) continue ;
			mpp[i][Revx[v]] = t[i][k];
		}

	for ( int i = 1; i <= q; i ++) {
		int x = X[i], y = Y[i];
		
		ll res = inf;
		
		for ( auto v : bl[x])
			res = min(res, w[x] + w[y] + ans[v][Rev[y]] + mpp[v][Revx[x]]);
		
		cout << res << '\n';
	}

	return 0;
}

