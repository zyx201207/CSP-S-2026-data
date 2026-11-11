//GZ-S00140 贵阳市第一中学 赵思翰

#include<bits/stdc++.h>
using namespace std;

const int MAXM = 5e5 + 5;
const int MAXN = 505;

int c, n, m, d, q;
int tw[MAXN];
int t[MAXM][MAXN];
int k[MAXN];
int dis[MAXM];
int ans;

struct Node{
	int d, u, ty;
	bool operator < (const Node& a)const{
		return d > a.d;
	}
};

vector<pair<int, int> >g[MAXN];

void bfs(int st, int ed) {
	int vis[MAXM];
	memset(vis, 0, sizeof(vis));
	priority_queue<Node> pq;
	
	vis[st] = 1;
	pq.push({tw[st], st, -1});
	
	while(!pq.empty()) {
		int dis = pq.top().d, u = pq.top().u, tu = pq.top().ty;
		pq.pop();
		
		if(u == ed) {
			ans = min(ans, dis + tw[ed] + t[u][tu]);
			return;
		}
		
		for(int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].first, tv = g[u][i].second;
			if(vis[v]) continue;
			vis[v] = 1;
			if(tu == -1) pq.push({dis + t[u][tv], v, tv});
			else if(tu == tv) pq.push({dis, v, tv});
			else pq.push({dis + t[u][tu] + t[u][tv], v, tv});
		}
	}
}

int main() {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> tw[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		int a[30];
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[j];cin >> t[a[j]][i];
		}
		for(int j = 2; j <= k[i]; j++) {
			g[a[j]].push_back({a[j - 1], i});
			g[a[j - 1]].push_back({a[j], i});
		}
	}
	
	while(q--) {
		int x, y;
		ans = 0x3f;
		cin >> x >> y;
		bfs(x, y);
		cout << ans << endl; 
	}
	
	
	return 0;
} 
