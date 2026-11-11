#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 1, MAXK = 1e3 + 1;
const int inf = 1e18;

int testnum, n, m, d, q, w[MAXN], dis[MAXK][MAXK], eln[MAXK][MAXK];
struct Edge {
	int y, w;
};
bool vis[MAXN];
vector<Edge> sta[MAXN], c[MAXN];
struct node {
	int x, dis;
	bool operator < (const node &oth) const {
		return dis > oth.dis;
	}
};
void dijkstra(int dis[], int st) {
	priority_queue<node> q;
	fill(dis + 1, dis + n + 1, 1e18);
	fill(vis + 1, vis + n + 1, false);
	q.push({st, 0});
	dis[st] = 0;
	while(!q.empty()) {
		int x = q.top().x;
		q.pop();
		if(vis[x]) {
			continue;
		}
		vis[x] = true;
		for(int y = 1; y <= n; y++) {
			if(y != x && eln[x][y] != inf) {
				if(dis[y] > dis[x] + eln[x][y]) {
					dis[y] = dis[x] + eln[x][y];
					q.push({y, dis[y]});
				}
			}
		}
	}
	return;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> testnum >> n >> m >> d >> q;    //n是线路数！！！ m 才是站台数量，m范围更大 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			eln[i][j] = inf;
		}
	}
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1, k; i <= n; i++) {
		cin >> k;
		for(int j = 1, st, len; j <= k; j++) {
			cin >> st >> len;
			sta[st].push_back({i, len});
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < (int)sta[i].size(); j++) {
			for(int k = j + 1; k < (int)sta[i].size(); k++) {
				int nd1 = sta[i][j].y, nd2 = sta[i][k].y;
				eln[nd1][nd2] = min(eln[nd1][nd2], sta[i][j].w + sta[i][k].w);
				eln[nd2][nd1] = min(eln[nd2][nd1], sta[i][j].w + sta[i][k].w);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		dijkstra(dis[i], i);
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for(int i = 0; i < (int)sta[x].size(); i++) {
			for(int j = 0; j < (int)sta[y].size(); j++) {
				int nd1 = sta[x][i].y, nd2 = sta[y][j].y;
				int w1 = sta[x][i].w, w2 = sta[y][j].w;
				ans = min(ans, w1 + w2 + dis[nd1][nd2]);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
//2026.10.31 15:27 
//等等你是说92行的代码一遍过两个小样例吗
//测下大阳历试试 
//2026.10.31 15:30
//大洋里都测过一遍了，没有问题
//第七个大洋里0.5秒卡卡应该能过
//诈骗题吗，嘻嘻爱抚你这家伙 

//明明就不喜欢牵手
//为何却主动把手勾
//你的心事太多
//我不会戳破 
