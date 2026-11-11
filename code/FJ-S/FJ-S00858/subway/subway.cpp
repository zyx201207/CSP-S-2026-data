#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 510;
const int M = 5e5 + 10;
const int D = 30;
const int Q = 1e5 + 10;
int c, n, m, d, q;

int w[M], k[N], dis[N + M + 10];

struct Edge{
	int next;
	int to;
	int dis;
}edge[100 * M];

int edge_num, head[M + N + 10];

void add(int x, int y, int v) {
	edge[++ edge_num].next = head[x];
	edge[edge_num].to = y;
	edge[edge_num].dis = v;
	head[x] = edge_num;
	
	return ;
}

void dij(int s) {
	memset(dis, 0x3f3f, sizeof(dis));
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push({0, s});
	while(q.size()) {
		auto u = q.top();
		q.pop();
		int x = u.second;
		for(int i = head[x] ; i ; i = edge[i].next) {
			int y = edge[i].to;
			int v = edge[i].dis;
			if(dis[x] + v >= dis[y]) 
				continue;
			dis[y] = dis[x] + v;
			q.push({dis[y], y});
		}
	}
	return ;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1 ; i <= m ; i ++) 
		cin >> w[i];
		
	for(int i = 1 ; i <= n ; i ++) {
		cin >> k[i];
		for(int j = 1 ; j <= k[i] ; j ++) {
			int a, t;
			cin >> a >> t;
			add(m + i, a, t);
			add(a, m + i, t);
		}
		
	}
	
	for(int i = 1 ; i <= q ; i ++) {
		int x, y;
		cin >> x >> y;
		dij(x);
		
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	
	return 0;
}
