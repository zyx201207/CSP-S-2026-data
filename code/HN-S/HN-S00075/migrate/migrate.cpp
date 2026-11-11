#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, d;

struct node {
	int u, dis;
};

int bfs(int u, int v, vector<vector<int>> edges) {
	
	queue<node> q;
	q.push({u, 0});
	
	vector<int> flg(n + 1, 0);
	
	while(!q.empty()) {
		node cur = q.front();
		q.pop();
		
		if(cur.u == v)
			return cur.dis;
		
		if(flg[cur.u])
			continue;
		flg[cur.u] = 1;
		
			
		for(auto i : edges[cur.u]) {
			q.push({i, cur.dis + 1});
		}
	}
	
	return -1;
}

int bfs2(int u, int v, vector<vector<int>> edges, int m) {
	queue<node> q;
	
	q.push({u, 0});
	
	vector<int> flg(n + 1, 0), dis(n + 1, 0);
	
	
	while(!q.empty()) {
		node cur = q.front();
		q.pop();
		
		//cout << flg[cur.u] << ' ' << cur.u << endl;
		
		if(flg[cur.u] > 3 || cur.dis > m)
			continue;
		
		flg[cur.u] ++;
		
		for(auto i : edges[cur.u]) {
			q.push({i, cur.dis + 1});
		}
	}
	
	return flg[v] == 2;
}


signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	
	while(t --) {
		
		
		cin >> n >> d;
		
		vector<int> num;
		vector<vector<int>> edges;
		edges.resize(n + 1);
		num.resize(n + 1);
		
		for(int i = 1; i <= n; i ++) {
			cin >> num[i];
		}
		
		for(int i = 1; i <= n; i ++) {
			for(int j = i + 1; j <= n; j ++) {
				
				if(num[j] - num[i] <= d) {
					
					edges[j].push_back(i);
					edges[i].push_back(j);
				}
			} 
		}
		
		int ans = 0;
		
		for(int i = 1; i <= n; i ++) {
			for(int j = i + 1; j <= n; j ++) {
				int dis = bfs(i, j, edges);
				if(dis == -1)
					continue;
				
				if(bfs2(i, j, edges, dis))
					ans ++;
			}
		}
		
		cout << ans << endl;
	}

	return 0;
}

