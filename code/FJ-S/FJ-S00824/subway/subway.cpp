#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct R {
	ll l;
	ll t;
};

const ll N = 500 + 10;
const ll M = 5e5 + 10;

ll w[M];
ll k[N];

vector < R > line[M];

vector < ll > a[N];
vector < ll > t[N];

ll G[N][N];

ll c, n, m, d, q;

int main() {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	fill(&G[0][0], &G[0][0] + N * N, 1e18);
	for (int i = 1; i <= n; i ++) {
		G[i][i] = 0;
	}
	for (ll i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	
	for (ll i = 1; i <= n; i ++) {
		cin >> k[i];
		
		for (ll j = 1; j <= k[i]; j ++) {
			ll A, T;
			cin >> A >> T;
			
			a[i].push_back(A);
			t[i].push_back(T);
			
			R r;
			r.l = i;
			r.t = T;
			line[A].push_back(r);
		}
	}
	
	for (ll i = 1; i <= n; i ++) {
		for (ll j = 0; j < k[i]; j ++) {
			for (ll l = 0; l < line[a[i][j]].size(); l ++) {
				ll v = line[a[i][j]][l].l;
				
				G[i][v] = G[v][i]
						= min(G[i][v], t[i][j] + line[a[i][j]][l].t);
			}
		}
	}
	
	for (ll l = 1; l <= n; l ++) {
		for (ll i = 1; i <= n; i ++) {
			for (ll j = 1; j <= n; j ++) {
				G[i][j] = G[j][i] = min(G[i][j], G[i][l] + G[l][j]);
			}
		}
	}
	
	while (q --) {
		ll s, t;
		cin >> s >> t;
		
		ll ans = 1e18;
		
		for (int i = 0; i < line[s].size(); i ++) {
			for (int j = 0; j < line[t].size(); j ++) {
				ans = min(ans, 
					 line[s][i].t + line[t][j].t +
					 G[line[s][i].l][line[t][j].l]);
					
			}
		}
		
		cout << ans + w[s] + w[t] << "\n";
	}
	
	return 0;
}
