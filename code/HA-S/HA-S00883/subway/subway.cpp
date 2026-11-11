#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, w[500005], ti[500005];
vector<pair<int, int> > a[500005], zhan[500005];
bool vis[500005];
void dijistra(int x, int y) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	memset(ti, 0x3f3f, sizeof(ti));
	memset(vis, 0, sizeof(vis));
	q.push({w[x], x});
	ti[x] = w[x];
	while(!q.empty()) {
		pair<int, int> gjr = q.top();
		q.pop();
		int dis = gjr.first;
		int pos = gjr.second;
		if(vis[pos]) continue;
		vis[pos] = 1;
		for(int i = 0;i < zhan[pos].size();i++) {
			int xian = zhan[pos][i].first;
			for(int j = 0;j < a[xian].size();j++) {
				int next = a[xian][j].first, nee = ti[pos] + zhan[pos][i].second + a[xian][j].second;
				if(ti[next] > nee) {
					ti[next] = nee;
					q.push({nee, next});
				}
			}
		}
	}
	cout << ti[y] + w[y] << "\n";
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int qw = 1;qw <= n;qw++) {
		int len;
		cin >> len;
		while(len--) {
			int x, y;
			cin >> x >> y;
			a[qw].push_back({x, y});
			zhan[x].push_back({qw, y});
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		dijistra(x, y);
	}
	return 0;
}
