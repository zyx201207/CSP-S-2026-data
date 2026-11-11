#include <bits/stdc++.h>
#define int long long
using namespace std;

int dist[510][510];
vector<pair<int, int> > sta[500010];
int w[500010];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	memset(dist, 0x3f, sizeof dist);
	
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		int k;
		cin >> k;
		
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			sta[a].push_back(make_pair(i, t));
		}
	}
	
	for (int i = 1; i <= m; i++) {
		int sz = sta[i].size();
		
		for (int j = 0; j < sz; j++) {
			for (int k = j + 1; k < sz; k++) {
				int pj = sta[i][j].first, dj = sta[i][j].second;
				int pk = sta[i][k].first, dk = sta[i][k].second;
				dist[pj][pk] = dist[pk][pj] = min(dist[pj][pk], dj + dk);
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	while (q--) {
		int a, b;
		cin >> a >> b;
		
		int ans = LLONG_MAX;
		int acnt = sta[a].size(); 
		int bcnt = sta[b].size();
		
		for (int i = 0; i < acnt; i++) {
			for (int j = 0; j < bcnt; j++) {
				int pi = sta[a][i].first, di = sta[a][i].second;
				int pj = sta[b][j].first, dj = sta[b][j].second;
				
				ans = min(ans, dist[pi][pj] + dj + di + w[a] + w[b]);
			}
		}
		cout << ans << endl;
	}
}
