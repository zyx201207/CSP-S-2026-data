#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
long long w[maxn];

struct Node{
	int to;
	int route;
};

vector<Node> g[maxn];
unordered_map<int , long long> cost[maxn];

struct dijNode{
	int curRoute;
	int u;
};

pair<long long,dijNode> add(long long d , int curRoute , int u){
	pair<long long , dijNode> tmp;
	tmp.first = d;
	tmp.second.curRoute = curRoute;
	tmp.second.u = u;
	return tmp;
}

long long dis[maxn];
void dij(int s){
	memset(dis , 0x3f , sizeof(dis));
	
	dis[s] = 0;
	queue<pair<long long ,dijNode> > q;
	//对s 进行第一轮的拓展
	for(int i = 0;i<g[s].size();i++){
		int v = g[s][i].to;
		int route = g[s][i].route;
		q.push(add(cost[s][route] + cost[v][route] , route , v));
		dis[v] = cost[s][route] + cost[v][route];
//		cout << v << " " << dis[v] << endl;
	} 
//	vis[s] = true;
	while(!q.empty()){
		pair<long long ,dijNode> now = q.front();
		q.pop();
		int u = now.second.u;
		long long rd = now.first;
		int croute = now.second.curRoute;
//		cout << u << " " << rd << " " << croute << endl;
		for(int i = 0;i<g[u].size();i++){
			int v = g[u][i].to;
			int route = g[u][i].route;
			if(croute == route){
				//可以直接开过去
				if(dis[v] > rd + cost[v][route]){
					dis[v] = rd + cost[v][route];
					q.push(add(dis[v] , route , v));
				} 
			}else{
				//需要换乘
				if(dis[v] > rd + cost[v][route] + cost[u][route]){
//					cout << v  << endl;
//					cout << rd << " " << g[u][i].costSelf << " " << g[u][i].costoth << endl;
					dis[v] = rd + cost[v][route] + cost[u][route];
					q.push(add(dis[v] , route , v));
				} 
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	int c , n , m , d , q;
	//测试点，地铁线路数，地铁站数，最多被几条路线经过，
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	} 
	for(int i = 1;i<=n;i++){
		int k;
		cin >> k;
		vector<int> nroute;
		nroute.reserve(k);
		for(int j = 1;j<=k;j++){
			int a , tt;
			cin >> a >> tt;
			cost[a][i] = tt;
			for(int m = 0;m<nroute.size();m++){
				g[a].push_back({nroute[m] , i});
				g[nroute[m]].push_back({a , i});
			}
			nroute.push_back(a);
		}
	}
	
	for(int i = 1;i<=q;i++){
		int s,e;
		cin >> s >> e;
		dij(s);
		cout << dis[e] + w[s] + w[e] << endl;
	}
	return 0;
}
/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
