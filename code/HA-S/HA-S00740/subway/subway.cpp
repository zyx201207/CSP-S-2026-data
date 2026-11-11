#include <bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define pii pair <int, int>

using namespace std;
const int N = 505, M = 5e5+5; 
int cid, n, m, d, q, tot, vs[M], sz[M]; 
ll w[M], g[N][N]; 
vector <pii> ds[M]; 

int main () {
//	system("fc subway7.ans subway.out /w"); return 0; 
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
//	auto ST = clock(); 
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0); 
	cin >> cid >> n >> m >> d >> q; 
	for (int i = 1;i <= m;i++) cin >> w[i]; 
	for (int i = 1;i <= m;i++) ds[i].reserve(20); 
	for (int i = 1;i <= n;i++) {
		int k; cin >> k; 
		for (int j = 1;j <= k;j++) {
			int a, t; cin >> a >> t;  
			ds[a].emplace_back(i, t); 
		}
	}
	memset(g, 0x3f, sizeof g); 
	for (int i = 1;i <= n;i++) g[i][i] = 0; 
	for (int i = 1;i <= m;i++) {
		for (auto j : ds[i]) {
			for (auto z : ds[i]) {
				g[j.fi][z.fi] = min(g[j.fi][z.fi], (ll)j.se+z.se); 				
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			for (int z = 1;z <= n;z++) {
				g[j][z] = min(g[j][z], g[j][i]+g[i][z]); 
			}
		}
	}
	while (q--) {
		int x, y; cin >> x >> y; 
		ll ans = 1e18; 
		for (auto j : ds[x]) {
			for (auto z : ds[y]) {
				ans = min(ans, g[j.fi][z.fi]+j.se+z.se); 
			}
		}
		cout << ans+w[x]+w[y] << "\n"; 
	}
//	auto ED = clock(); 
//	cerr << (ED-ST)*1.0/CLOCKS_PER_SEC; 
	return 0; 
}
/*
Part of my heart was left behind that day
I remember every time I smell the rain
*/
