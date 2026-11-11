#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define int long long
#define pii pair<int,int>

using namespace std;
const int MAXM = 5e5 + 10;
const int MAXN = 510;
const int MAXQ = 1e5 + 10;
const int INF = 1e17;
struct station {
	int a, t;
} st[MAXN][MAXM];
struct Node {
	int v, w;
};
vector<Node> mp[MAXM];
int c, n, m, d, q;
int w[MAXM];
int k[MAXN];
int x[MAXQ], y[MAXQ];
int dij(int st, int ed) {
	bool vis[MAXM];
	int dis[MAXM];
	priority_queue<pii> pq;
	pq.push(make_pair(0, st));
	for(int i = 1;i <= m;i ++) {
		dis[i] = INF;
		vis[i] = 0;
	}
	dis[st] = 0;
	while(pq.size()) {
		pii cu = pq.top();
		pq.pop();
		if(vis[cu.second]) continue;
		vis[cu.second] = 1;
		for(Node to : mp[cu.second]) {
			if(dis[to.v] > dis[cu.second] + to.w) {
				dis[to.v] = dis[cu.second] + to.w;
				pq.push(make_pair(dis[to.v], to.v));
			}
		}
	}
	return dis[ed];
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++) {
		cin >> k[i];
		for(int j = 1;j <= k[i];j ++) {
			cin >> st[i][j].a >> st[i][j].t;
		}
		for(int j = 1;j < k[i];j ++) {
			int w = st[i][j].t + st[i][j + 1].t;
			mp[st[i][j].a].push_back(Node {st[i][j + 1].a, w});
			mp[st[i][j + 1].a].push_back(Node {st[i][j].a, w});
		} 
	}
	for(int i = 1;i <= q;i ++) {
		cin >> x[i] >> y[i];
		cout << dij(x[i], y[i]);
		if(i != q) cout << '\n';
	}
	return 0;
}

