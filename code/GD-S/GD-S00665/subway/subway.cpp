#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 500010
#define M 510

struct node {
	int w, v;
};
struct que {
	int w, v;
};
struct nodee {
	int w, a;
};
struct query {
	int x, y, ans, id;
}qry[N];
int C, n, m, d, Q;
int w[N];
int k[N];
vector<nodee> l[N];
vector<int> le[N];
vector<node> e[N];
bool operator<(que x, que y) {
	return x.v < y.v;
}
int dis[N];
int tzdis[M][M];
bool vis[N]; 
map<int, map<int, int> > ans;
void dijkstra(int s) {
	priority_queue<que> q;
	fill(dis + 1, dis + m + 1, 1e15);
	fill(vis + 1, vis + m + 1, 0);
	dis[s] = 0;
	q.push({s, 0});
	while(q.size() != 0) {
		que h = q.top();
		q.pop();
		if(vis[h.w] == true) {
			continue;
		}
		vis[h.w] = true;
		for(auto i:e[h.w]) {
			if(dis[i.w] > dis[h.w] + i.v && vis[i.w] == false) {
				dis[i.w] = dis[h.w] + i.v;
				q.push({i.w, dis[i.w]});
			}
		}
	}
}
void bfs(int s) {
	queue<int> bq;
	fill(dis + 1, dis + m + 1, 1e15);
	dis[s] = 0;
	bq.push(s);
	while(bq.size() != 0) {
		int h = bq.front();
		bq.pop();
		for(auto i:le[h]) {
			int num = 0;
			for(auto j:l[i]) {
				if(j.w == h) {
					num = j.a;
					break;
				}
			}
			for(auto j:l[i]) {
				if(dis[h] + num + j.a < dis[j.w]) {
					dis[j.w] = dis[h] + num + j.a;
					bq.push(j.w);
				}
			}
		}
	}
}

bool cmp1(query x, query y) {
	return x.x < y.x;
}
bool cmp2(query x, query y) {
	return x.id < y.id;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> C >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++) {
		cin >> k[i];
		for(int j = 1;j <= k[i];j++) {
			int w, a;
			cin >> w >> a;
			l[i].push_back({w, a});
			le[w].push_back(i);
		}
	}
	for(int i = 1;i <= Q;i++) {
		cin >> qry[i].x >> qry[i].y;
		qry[i].id = i;
	}
	sort(qry + 1, qry + Q + 1, cmp1);
	if(7 <= C && C <= 11) {
		for(int i = 1;i <= n;i++) {
			if(k[i] == 2) {
				e[l[i][0].w].push_back({l[i][1].w, l[i][0].a + l[i][1].a});
				e[l[i][1].w].push_back({l[i][0].w, l[i][0].a + l[i][1].a});
			}
		}
		for(int i = 1;i <= Q;i++) {
			if(qry[i].x != qry[i - 1].x) {
				dijkstra(qry[i].x);
			}
			qry[i].ans = dis[qry[i].y] + w[qry[i].x] + w[qry[i].y];
		}
	} else if(12 <= C && C <= 19) {
		int z = l[1][0].a;
		memset(tzdis, 0x3f, sizeof(tzdis));
		for(int i = 1;i <= n;i++) {
			tzdis[i][i] = 0;
		}
		for(int i = 1;i <= m;i++) {
			for(auto j:le[i]) {
				for(auto k:le[i]) {
					if(j != k) {
						tzdis[j][k] = 2 * z;
						tzdis[k][j] = 2 * z;
					}
				}
			}
		}
		
		for(int k = 1;k <= n;k++) {
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= n;j++) {
					tzdis[i][j] = min(tzdis[i][j], tzdis[i][k] + tzdis[k][j]);
				}
			}
		}
		
		for(int i = 1;i <= Q;i++) {
			qry[i].ans = 1e15;
			for(auto j:le[qry[i].x]) {
				for(auto k:le[qry[i].y]) {
					qry[i].ans = min(qry[i].ans, tzdis[j][k] + w[qry[i].x] + w[qry[i].y] + 2 * z);
				}
			}
		}
	} else {
		for(int i = 1;i <= Q;i++) {
			if(qry[i].x != qry[i - 1].x) {
				bfs(qry[i].x);
			}
			qry[i].ans = dis[qry[i].y] + w[qry[i].x] + w[qry[i].y];
		}
	}
	sort(qry + 1, qry + Q + 1, cmp2);
	for(int i = 1;i <= Q;i++) {
		cout << qry[i].ans << "\n";
	}
	return 0;
} 
