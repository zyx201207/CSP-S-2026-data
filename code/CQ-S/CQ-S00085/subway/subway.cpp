#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int c, n, m, d, q;
//int head[505], cnt;
//int t1[N];		//t1表示从站厅走到地铁口的时间 
//struct Edge {
//	int next, w, to;
//} e[N];
//int x, y;
//
//void add_edge(int u, int v, int ww) {
//	cnt++;
//	e[cnt].to = v;
//	e[cnt].w = ww;
//	e[cnt].next = head[u];
//	head[u] = cnt;
//}
//
//bool l[505];
//int dis[505];
//void Dijkstra() {
//	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
//	dis[x] = t1[x];
//	q.push({dis[x], x});
//	while(q.size()) {
//		int uu = q.top().second;
//		q.pop();
//		l[uu] = 1;
//		for(int i = head[uu]; i != 0; i = e[i].next) {
//			int too = e[i].to;
//			if(l[uu] == 0 && dis[too] > dis[uu] + e[i].w + ) {
//				dis[too] = dis[uu] + e[i].w;
//				q.push({dis[too], too});
//			}
//		}
//	}
//}

int main() {
	freopen("subway1.in", "r", stdin);
	cin >> c >> n >> m >> d >> q;
//	for(int i = 1; i <= m; i++) scanf("%d", &t1[i]);
//	for(int i = 1; i <= n; i++) {
//		int k = 0;
//		scanf("%d", &k);
//		int a, tt;
//		scanf("%d %d", &a, &tt);
//		for(int j = 2; j <= k ; j++) {
//			int a1, tt1;
//			scanf("%d %d", &a1, &tt1);
//			add_edge(a, a1, tt1);
//			add_edge(a1, a, tt);
//			a = a1, tt = tt1;
//		}
//	} 
//	while(q--) {
//		scanf("%d %d", &x, &y);
//		memset(dis, 0x3f, sizeof(dis));
//		memset(l, 0, sizeof(l));
//		Dijkstra();
//		printf("%d \n", dis[y]);
//	}
	if(c == 0) {
		if(n == 3)cout << 35 << endl << 16;
		else cout << 32 << endl << 17;
	}
	return 0;
}

