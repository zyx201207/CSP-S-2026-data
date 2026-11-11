#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5, M = 2e6 + 5;

int c, n, m, d, Q;
ll w[N], dis[M], ans[N];
bool vis[M];
vector<int> g[N];
vector<pair<int, int> > qu[N];
vector<pair<int, int> > e[M];
priority_queue<pi, vector<pi>, greater<pi> > q;
deque<int> p;
int id(int k, int u){ //k ²ã£¬op = 0 Ìü op = 1 Ì¨£¬u Õ¾ 
	return k * m + u;
}

//void dfs(int u){
//	if(vis[u]) return;
//	vis[u] = 1;
//	sz++;
//	for(auto v : e[u]){
//		dfs(v.fi);
//	}
//}

void Dij(){
	while(!q.empty()){
		int u = q.top().se;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto v : e[u]){
			if(dis[v.fi] > dis[u] + v.se){
				dis[v.fi] = dis[u] + v.se;
				q.push({dis[v.fi], v.fi});
			}
		}
	}
}

void BFS(){
	while(!p.empty()){
		int u = p.front();
		p.pop_front();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto v : e[u]){
			if(!v.se){
				if(dis[v.fi] > dis[u]){
					dis[v.fi] = dis[u];
					p.push_front(v.fi);
				}
			} else {
				if(dis[v.fi] > dis[u] + v.se){
					dis[v.fi] = dis[u] + v.se;
					p.push_back(v.fi);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	d = 0;
	for(int i = 1, x;i <= n;i++){
		cin >> x;
		int la = 0;
		for(int j = 1, a, t;j <= x;j++){
			cin >> a >> t;
			g[a].push_back(i);
			//cout << "g: " << a << ' ' << i << '\n';
			int k = g[a].size();
			int x = a, y = id(k, a);
			e[x].push_back({y, t});
			e[y].push_back({x, t});
			//cout << "one: " << x << ' ' << y << ' ' << t << '\n';
			if(la){
				e[la].push_back({y, 0});
				e[y].push_back({la, 0});
				//cout << "two: " << la << ' ' << y << '\n';
			}
			la = y;
		}
	}
	
	for(int i = 1;i <= m;i++){
		int len = g[i].size();
		d = max(d, len);
//		cout << "i: " << i << ' ' << len << '\n';
//		for(auto v : g[i]){
//			cout << v << ' ';
//		}
//		cout << '\n';
	}
	
	n = m * (d + 1);
	//dfs(1);
	//cout << (sz == n) << '\n';
	
	if(m <= 1000){
		memset(ans, 0x3f, sizeof(ans));
		for(int i = 1, x, y;i <= Q;i++){
			cin >> x >> y;
			qu[x].push_back({i, y});
		}
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= n;j++){
				dis[j] = 1e18, vis[j] = 0;
			}
			dis[i] = 0;
			q.push({0, i});
			Dij();
			for(auto j : qu[i]){
				ans[j.fi] = min(ans[j.fi], dis[j.se] + w[i] + w[j.se]);
			}
		}
		
		for(int i = 1;i <= Q;i++){
			cout << ans[i] << '\n';
		}
	} else {
		while(Q--){
			int x, y;
			cin >> x >> y;
			for(int i = 1;i <= n;i++){
				dis[i] = 1e18, vis[i] = 0;
			}
			dis[x] = 0;
			p.push_back(x);
			BFS();
			cout << dis[y] + w[x] + w[y] << '\n';
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3 
*/
