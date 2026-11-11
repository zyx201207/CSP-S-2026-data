#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,T;
int w[500005];
int k[500005];
int len[505];
struct node{
	int id,w;
};
	int cc = 0;
vector<node>D[500005];
int f[505][505];
int dis[505];
struct pi{
	int v,w;
};
vector<pi>E[505],G[505],la[505];
bool vis[505];
struct ppi{
	int x,s;
	bool operator < (const ppi& nxt) const{
		return nxt.s < s;
	}
};
priority_queue<ppi>q;
void dij(){
	q.push({1 , 0});
	for(int i = 1 ; i <= n + 2 ; i ++){
		dis[i] = 100000000000000;
	}
	dis[1] = 0;
	while(!q.empty()){
		ppi u = q.top();
		q.pop();
		vis[u.x] = 0;
		cc ++;
//		cout << u.x << "\n";
		for(int i = 0 ; i < E[u.x].size() ; i ++){
			cc += 4;
			int v = E[u.x][i].v;
			int w = E[u.x][i].w;
			if(dis[u.x] + w < dis[v]){
				len[v] = 0;
				if(la[v].size() == 0){
					la[v].push_back({u.x , w});
				}else{
					la[v][len[v]].v = u.x;
					la[v][len[v]].w = w;
				}
				len[v] ++;
				dis[v] = dis[u.x] + w;
				if(!vis[v]){
					vis[v] = 1;
					q.push({v , dis[v]});
				}
			}else if(dis[u.x] + w == dis[v]){
				if(la[v].size() == len[v]){
					la[v].push_back({u.x , w});
				}else{
					la[v][len[v]].v = u.x;
					la[v][len[v]].w = w;
				}
				len[v] ++;
			}
		}
	} 
}
void dijk(){
	q.push({n + 1 , 0});
	for(int i = 1 ; i <= n + 2 ; i ++){
		dis[i] = 100000000000000;
	}
	dis[n + 1] = 0;
	while(!q.empty()){
		ppi u = q.top();
		q.pop();
		vis[u.x] = 0;
//		cout << u.x << "\n";
		for(int i = 0 ; i < G[u.x].size() ; i ++){
			int v = G[u.x][i].v;
			int w = G[u.x][i].w;
			if(dis[u.x] + w < dis[v]){
				dis[v] = dis[u.x] + w;
				if(!vis[v]){
					vis[v] = 1;
					q.push({v , dis[v]});
				}
			} 
		}
	} 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> T;
	for(int i = 1 ; i <= m ; i ++){
		cin >> w[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		cin >> k[i];
		for(int j = 1 ; j <= k[i] ; j ++){
			int x,y;
			cin >> x >> y;
			D[x].push_back({i , y});
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			f[i][j] = 100000000000000;
		}
	}
	for(int i = 1 ; i <= m ; i ++){
		for(int j = 0 ; j < D[i].size() ; j ++){
			int x = D[i][j].id;
			for(int k = j + 1 ; k < D[i].size() ; k ++){
				int y = D[i][k].id;
				int q = D[i][j].w,p = D[i][k].w;
//				cout << x << " " << y << " " << i << "\n";
				f[x][y] = min(f[x][y] , q + p);
				f[y][x] = f[x][y];
			}
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			if(f[i][j] > 100000000000000)continue;
			E[i].push_back({j , f[i][j]});
		}
	}
	dij(); 
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 0 ; j < la[i].size() ; j ++){
			int x = la[i][j].v;
			int w = la[i][j].w;
//			cout << x << " " << i << " " << w << "\n";
			if(x > n)continue;
			G[x].push_back({i , w});
			G[i].push_back({x , w});
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		G[i].push_back({n + 1 , 100000000000000});
		G[n + 1].push_back({i , 100000000000000});
		G[i].push_back({n + 2 , 100000000000000});
		G[n + 2].push_back({i , 100000000000000});
	}
	while(T --){
		int x,y;
		cin >> x >> y;
		cc = 0;
		for(int i = 0 ; i < D[x].size() ; i ++){
			cc += 6;
			int v = D[x][i].id;
			int w = D[x][i].w;
//			cout << E[n + 1].size() << " " << v - 1 << endl;
			G[n + 1][v - 1].w = w;
		}
		for(int i = 0 ; i < D[y].size() ; i ++){
			cc += 8;
			int v = D[y][i].id;
			int w = D[y][i].w;
			int s = G[v].size();
			G[v][s - 1].w = w;
		}
		dijk();
		cout << dis[n + 2] + w[x] + w[y] << "\n";
		for(int i = 0 ; i < D[x].size() ; i ++){
			int v = D[x][i].id;
			G[n + 1][v - 1].w = 100000000000000;
		}
		for(int i = 0 ; i < D[y].size() ; i ++){
			int v = D[y][i].id;
			int s = G[v].size();
			G[v][s - 1].w = 100000000000000;
		}
//		cout << cc << "\n";
	}
//	cout << cc << endl;
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
