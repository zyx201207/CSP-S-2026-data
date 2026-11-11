//44pts + 32pts = 76pts
#include<bits/stdc++.h>
bool Mst;
#define ll long long
#define pil pair<int, ll>
#define Fi first
#define Se second
using namespace std;
const int N = 5e5 + 10;
const int M = 510;
const ll inf = 4e18;
int c, n, m, d, q;		//swap(n, m) 
ll w[N];
vector<int> p[N];
vector<pil> vt[M];
//#1~#11 
const int N11 = 1010;
struct Node{
	int u; ll w;
	bool operator <(const Node &_) const {
		return w > _.w;
	}
}; 
ll dis11[N11][N11];
void dij11(int s){
	priority_queue<Node> q;
	dis11[s][s] = 0;
	q.push({s, dis11[s][s]});
	while(!q.empty()){
		int x = q.top().u;
		ll now = q.top().w;
		q.pop();
		if(now != dis11[s][x]) continue;
		for(auto i : p[x]){
			ll wx = 0;
			for(auto j : vt[i]){
				int y = j.Fi;
				if(x == y){
					wx = j.Se;
					break;
				}
			}
			for(auto j : vt[i]){
				int y = j.Fi;
				ll wy = j.Se;
				if(y == x) continue;
				if(dis11[s][y] > dis11[s][x] + wx + wy){
					dis11[s][y] = dis11[s][x] + wx + wy;
					q.push({y, dis11[s][y]});
				}
			}
		}
	}
	return ;
}
//#12~#19
vector<int> E[M];
ll dis19[M][M];
void bfs(int s){
	queue<Node> q;
	dis19[s][s] = 1;
	q.push({s, dis19[s][s]});
	while(!q.empty()){
		int x = q.front().u;
		q.pop();
		for(auto y : E[x]){
			if(dis19[s][y] > dis19[s][x] + 1){
				dis19[s][y] = dis19[s][x] + 1;
				q.push({y, dis19[s][y]});
			}
		}
	}
	return ;
}
//#20~#25
ll dis[M][M];
pil Find(vector<pil> &vt, int k){
	int l = 0, r = vt.size() - 1;
	while(l < r){
		int mid = (l + r) >> 1;
		if(vt[mid].Fi >= k) r = mid;
		else l = mid + 1;
	}
	return vt[l];
}
void dij(int s){
	priority_queue<Node> q;
	dis[s][s] = 0;
	q.push({s, dis[s][s]});
	while(!q.empty()){
		int x = q.top().u;
		ll now = q.top().w;
		q.pop();
		if(now != dis[s][x]) continue;
		for(auto y : E[x]){
			for(auto i : vt[x]){
				pil j = Find(vt[y], i.Fi);
				if(j.Fi != i.Fi) continue;
				if(dis[s][y] > dis[s][x] + i.Se + j.Se){
					dis[s][y] = dis[s][x] + i.Se + j.Se;
					q.push({y, dis[s][y]});
				}
			}
		} 
	}
	return ;
}

bool Med;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cerr << "Memory is " << abs(&Med - &Mst) / 1024.0 / 1024 << "MB.\n";
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> c >> m >> n >> d >> q;
	for(int i = 1; i <= n; ++i) cin >> w[i];
	for(int i = 1; i <= m; ++i){
		int k; cin >> k;
		for(int j = 1; j <= k; ++j){
			int u; ll t;
			cin >> u >> t;
			vt[i].push_back(make_pair(u, t));
			p[u].push_back(i);
		}
		sort(vt[i].begin(), vt[i].end());
	}
	
	if(c <= 11){
		memset(dis11, 0x3f, sizeof dis11);
		for(int i = 1; i <= n; ++i) dij11(i);
		while(q--){
			int u, v;
			cin >> u >> v;
			cout << w[u] + dis11[u][v] + w[v] << '\n';
		}
		return 0;
	}
	
	for(int i = 1; i <= n; ++i){
		int len = p[i].size();
		for(int j = 0; j < len; ++j){
			for(int k = j + 1; k < len; ++k){
				int u = p[i][j], v = p[i][k];
				E[u].push_back(v);
				E[v].push_back(u);
			}
		}
	}
	if(c <= 19){
		ll T = vt[1][0].Se;
		memset(dis19, 0x3f, sizeof dis19);
		for(int i = 1; i <= m; ++i) bfs(i);
		while(q--){
			int u, v;
			cin >> u >> v;
			ll ans = inf;
			for(int i : p[u]){
				for(int j : p[v]){
					ans = min(ans, dis19[i][j]);
				}
			}
			ans = ans * 2 * T;
			cout << w[u] + ans + w[v] << '\n';
		}
		return 0;
	}
	
	//我感觉刚刚写的这个很有启发性，或许可以通过预处理铁路线之间的dis
	//然后询问时通过暴力枚举起终点所在的铁路线就可以做到 O(d^2 * q) 了，可以通过，先去打 T3T4 暴力，等一下来打 
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= m; ++i) dij(i);
	while(q--){
		int u, v;
		cin >> u >> v;
		ll ans = inf;
		for(int i : p[u]){
			ll wu = Find(vt[i], u).Se;
			for(int j : p[v]){
				ll wv = Find(vt[j], v).Se;
				ans = min(ans, wu + dis[i][j] + wv);
			}
		}
		cout << w[u] + ans + w[v] << '\n';
	}
	//怎么跑了5s+，冷静冷静，分析一下复杂度再看一看是不是哪里实现不好 
	//坏了，这个dij是log^2的 不能二分啊 难搞了 决策失误了 应该去写 T4 的，哎，算了算了，我已经尽力了 
	
	return 0;
}
/*
20 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
