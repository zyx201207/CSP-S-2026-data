#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 100;
int fath[maxn];

int n, k;


int find(int u) {
	
	if(fath[u] == u)
		return u;
		
	return fath[u] = find(fath[u]);
}

struct node {
	int u, w;
};

bool check(vector<int> ch, vector<vector<int>> tree) {
	
	vector<int> flg(n + 1, 0);
	
	for(int i = 1; i <= n; i ++)
		fath[i] = i;
	for(auto i : ch)
		flg[i] = 1;
		
	int cnt = k;
	
	for(int i = 1; i <= n; i ++) {
		if(!flg[i])
			continue;
		
		for(auto j : tree[i]) {
			if(!flg[j])
				continue;
			
			int fi = find(i), fj = find(j);
			
			if(fi != fj) {
				cnt --;
				fath[fi] = fj;
			}
		}
	}
	
	//cout << cnt << endl;
	return cnt <= 2;
}

int bfs(int u, vector<vector<int>> tree, vector<int> ch) {
	queue<node> q;
	q.push({u, 0});
	
	vector<int> flg(n + 1, 0), cx(n + 1, 0);
	
	for(auto i : ch)
		cx[i] = 1;
	
	while(!q.empty()) {
		node cur = q.front();
		q.pop();
		
		if(cx[cur.u])
			return cur.w;
		
		if(flg[cur.u])
			continue;
		flg[cur.u] = 1;
		
		for(auto i : tree[cur.u]) {
			q.push({i, cur.w + 1});
		}
	}
}

int calc(vector<int> ch, vector<vector<int>> tree) {
	
	int maxx = 0;
	for(int i = 1; i <= n; i ++) {
		maxx = max(maxx, bfs(i, tree, ch));
	}
	
	
	return maxx;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	while(t --) {
		
		cin >> n >> k;
		
		vector<vector<int>> tree;
		tree.resize(n + 1);
		
		for(int i = 1; i <= n - 1; i ++) {
			int u, v;
			cin >> u >> v;
			
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		
		const int mmsk = (1 << n) - 1;
		int ans = INT_MAX;
		
		for(int i = 0; i <= mmsk; i ++) {
			
			vector<int> ch;
			
			for(int j = 0; j < n; j ++) {
				if((i >> j) & 1 == 1)
					ch.push_back(j + 1);
			}
			
			if(ch.size() != k)
				continue; 
			
			if(check(ch, tree)) {
				ans = min(ans, calc(ch, tree));
				
			}
		}
		
		cout << ans << endl;
	}

	return 0;
}

