/*
想到思路了，但是暂时实现不了

将每条线路看作节点。
定义每个节点之间的距离为最短换乘距离的地铁站

然后随便 floyd 预处理 
每个查询分两类：
1.若有线路共享两站，则地铁距离为0
2.若需换乘，则找到最短的线路换乘

搞呗。。 
*/ 

#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int> 
#define fi first
#define se second

using namespace std;

const int N = 5e5 + 10, inf = 0x3f3f3f3f;

struct node{
	int w;
	int t[22];
	
	node(void){
		w = 0;
		memset(t, 0, sizeof(t));
	}
}p[N];

int c, n, m, d, q;
vector<vector<int> > line;

int dis[510][510];//line -> line

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q; 
	
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			if(i ^ j) dis[i][j] = inf;
	
	line.resize(n + 1);
	
	for(int i = 1; i <= m; ++ i) cin >> p[i].w;
	for(int i = 1; i <= n; ++ i){
		int k; cin >> k;
		for(int j = 1; j <= k; ++ j){
			int a, t; cin >> a >> t;
			line[i].push_back(a);
			p[a].t[i] = t;
		}
	}
	
//	for(int i = 1; i <= m; ++ i){
//		for(pii pi : p[i].t){
//			for(pii pip : p[i].t){
//				int l1 = pi.fi, t1 = pi.se, 
//					l2 = pip.fi, t2 = pip.se;
//				
//				dis[l1][l2] = min(dis[l1][l2], t1 + t2);
//				dis[l2][l1] = min(dis[l2][l1], t1 + t2);
//			}
//		}
//	}
	
//	for(int i = 1; i <= n; ++ i){
//		cout << i << ":";
//		for(int u : line[i]){
//			cout << u << ' ';
//		}
//		cout << '\n';
//	}
	
	for(int u = 1; u <= n; ++ u){
		for(int pp : line[u]){
			for(int v = 1; v <= n; ++ v){
				if(u == v || !p[pp].t[v]) continue;
				dis[u][v] = min(dis[u][v], p[pp].t[u] + p[pp].t[v]);
				dis[v][u] = dis[u][v];
			}
		}
	}
	
//	for(int i = 1; i <= n; ++ i){
//		for(int j = 1; j <= n; ++ j){
//			cout << dis[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	
	for(int i = 1; i <= n; ++ i){
		for(int j = i + 1; j <= n; ++ j){
			if(i == j) continue;
			for(int k = 1; k <= n; ++ k){
				if(k == i || k == j) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[j][i] = dis[i][j];
			}
		}
	}
	
	while(q --){
		int x, y; cin >> x >> y;
		int ans = p[x].w + p[y].w;
		
		//能直达
		int res1 = inf;
		queue<int> q;
		for(int i = 1; i <= 20; ++ i){
			if(p[x].t[i]) q.push(i);
		}
		int yy = inf;
		while(!q.empty()){
			int tmp = q.front(); q.pop();
			for(int point : line[tmp]){
				if(point == y){
					yy = p[x].t[tmp] + p[y].t[tmp];
					break;
				}
			}
			res1 = min(res1, yy);
		}
		
		//不能直达
		int res2 = inf;
		for(int i = 1; i <= 20; ++ i) {
			for(int j = 1; j <= 20; ++ j){
				if(!p[x].t[i] || !p[y].t[j] || i == j) continue;
				res2 = min(res2, p[x].t[i] + p[y].t[j] + dis[i][j]);
			}
		}
		
//		cout << res1 << ' ' << res2 << '\n';
		
		ans += min(res1, res2);
		cout << ans << '\n';
	}
	
	return 0;
}
