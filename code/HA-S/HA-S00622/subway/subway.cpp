#include <bits/stdc++.h>

#define ll long long

#define fileio(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout);

using namespace std;

const int maxn = 505;
const int maxm = 5e5 + 15;
const ll inf = 1e18;

int k[maxn];
vector<int> a[maxn], t[maxn];
vector<pair<int, int>> on[maxm];
ll dis[maxn][maxn];
int w[maxm];

int main() {
	fileio("subway")
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j];
			cin >> t[i][j];
			
			on[a[i][j]].emplace_back(i, j);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dis[i][j] = inf;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	} 
	
	for(int i = 1; i <= m; i++) {
		for(int ji = 0; ji < on[i].size(); ji++) {
			for(int ti = ji + 1; ti < on[i].size(); ti++) {
				int u = on[i][ji].first;
				int v = on[i][ti].first;
				int ui = on[i][ji].second;
				int vi = on[i][ti].second;
				
				dis[u][v] = min(dis[u][v], 1ll * t[u][ui] + t[v][vi]);
				dis[v][u] = min(dis[v][u], dis[u][v]);
			}
		}
	}
	
//	cout << dis[1][2] << endl;
	
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			if(i == k) continue;
			for(int j = i + 1; j <= n; j++) {
				if(j == k) continue;
				
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[j][i] = min(dis[j][i], dis[j][k] + dis[k][i]);
			}
		}
	}
	
	while(q--) {
		int l, r;
		cin >> l >> r;
		
		ll ans = inf;
		
		for(int i = 0; i < on[l].size(); i++) {
			for(int j = 0; j < on[r].size(); j++) {
				int u = on[l][i].first;
				int v = on[r][j].first;
				int ui = on[l][i].second;
				int vi = on[r][j].second;
				
				ans = min(ans, 1ll * t[u][ui] + dis[u][v] + t[v][vi]);
				
//				cout << "from " << u << " to " << v << ", spend " << t[u][ui] << " + " << dis[u][v] << " + " << t[v][vi] << endl;
			}
		}
		
		ans += w[l] + w[r];
		
		cout << ans << '\n';
	}
	
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
/*

*/
