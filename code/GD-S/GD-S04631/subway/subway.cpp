#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 505, MAXM = 5e5 + 5, MNODE = 1e6, MAX = 1e17 + 5;

struct node1{
	int to, val;
};

struct node{
	int di, bh;
	bool operator <(const node &x) const{
		return x.di < di;
	}
};

int c, n, m, d, qe, dis[MNODE];

vector<node1>edge[MNODE];

priority_queue<node>q;

void dj(int st) {
	for (int i = 1; i <= m * (n + 1) + 2 * m; i++) {
		dis[i] = MAX;
	}
	//memset(vis, 0, sizeof(vis))
	
	dis[st] = 0;
	q.push((node){0, st});
	
	while(!q.empty()) {
		int u = q.top().bh;
		q.pop();
		
		//cout << u << " " << dis[u] << endl;
		
		//cout << edge[u].size() << endl;
		
		for (node1 v : edge[u]) {
			//cout << u << " " << v << "asd" << endl;
			if (dis[v.to] > dis[u] + v.val) {
				dis[v.to] = dis[u] + v.val;
				q.push((node){dis[v.to], v.to});
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> qe;
	
	// 1 - m 表示的是地铁口
	// m + 1 - 2m 表示的是地铁站 	
	// (a + 1) * m + n  表示 a - n 即地铁a - n 
	int w;
	
	for (int i = 1; i <= m; i++) {
		cin >> w;
		edge[i].push_back((node1){i + m, w});
		edge[i + m].push_back((node1){i, w});
		//cout << i << " " << i + m << " " << w << endl;
	}
	
	int k;
	
	for (int i = 1; i <= n; i++) {
		cin >> k;
		int last = -1;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			int u = (a - 1) * (n + 1) + i + 2 * m;
			if (last == -1) {
				last = u;
			}
			else {
				edge[last].push_back((node1){u, 0});
				edge[u].push_back((node1){last, 0});
				//cout << last << " " << u << " " << 0 << endl;
				last = u;
			}
			edge[u].push_back((node1){a + m,t});
			edge[a + m].push_back((node1){u, t});
		//	cout << a << " " << i << " " << u << " " << a + m << " " << t << endl;
		}
	}
	
	for (int i = 1; i <= qe; i++) {
		int x, y;
		cin >> x >> y;
		
		dj(x);
//		for (int j = 1; j <= n; j++) {
//			cout << dis[j] << endl;
//		}
		
		
		cout << dis[y] << "\n";
	}
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
