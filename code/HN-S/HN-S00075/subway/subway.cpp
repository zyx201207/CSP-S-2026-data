#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 100;

struct node {
	int v, w;
};
struct que {
	int u, dis;
	friend bool operator < (que a, que b) {
		return a.dis > b.dis;
	}
};

vector<vector<node>> edges; 
vector<vector<int>> zht, gm; 
int c, n, m, d, q;

int dt[maxn], tsiz[maxn], cnt[maxn];

vector<int> dijstra(int u) {
	
	priority_queue<que> pq;
	vector<int> dis;
	dis.resize((m + 1) * d, INT_MAX);
	dis[u] = 0;
	
	pq.push({u, 0});
	
	while(!pq.empty()) {
		que cur = pq.top();
		pq.pop();
		
		for(auto i : edges[cur.u]) {
			
			if(dis[i.v] > cur.dis + i.w) {
				
				dis[i.v] = cur.dis + i.w;
				
				pq.push({i.v, dis[i.v]});
			}
		}
	}
	
	return dis;
}


signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	
	cin >> c >> n >> m >> d >> q; 
	
	edges.resize((m + 2) * d);
	zht.resize(m + 1);
	gm.resize(m + 1);
	
	for(int i = 1; i <= m; i ++) {
		cin >> dt[i];
	}
	
	int tot = m + 1;
	
	for(int i = 1; i <= n; i ++) {
		cin >> tsiz[i];
		
		int lst = 0;
		
		for(int j = 1; j <= tsiz[i]; j ++) {
			int x, t;
			cin >> x >> t;
			
			
			edges[x].push_back({tot, t});
			edges[tot].push_back({x, t});
			zht[x].push_back(tot);
			
			if(lst != 0) {
				int siz = zht[lst].size() - 1;
				
				edges[tot].push_back({zht[lst][siz], 0});
				edges[zht[lst][siz]].push_back({tot, 0});
				
				gm[x].push_back(lst);
				gm[lst].push_back(x);
			}
			
			lst = x;
			tot ++;
		}
	
	}
	
	unordered_map<int ,int> dis1; 
	
	for(int i = 1; i <= m; i ++) {
		if(edges[i].size() == 0)
			continue;
		
		vector<int> tmp = dijstra(i);
		
		for(int j = 1; j <= m; j ++) {
			dis1[i * m + j] = tmp[j];
		}
		
	}
	
	
	
	for(int i = 1; i <= q; i ++) {
		int x, y;
		cin >> x >> y;
		
		cout << dis1[x * m + y] + dt[x] + dt[y] << endl;
	}
	
	return 0;
}

