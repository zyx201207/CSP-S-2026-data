#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 5,M = 5e5 + 5;
int c,n,m,d,q;
vector<pair<pair<int,int>,int> > v[500005][25];
int w[M],unuse[M];
bool vis[M][25];
int dis[M][25];
int f[1005][1005];
void init(){
	for(int i = 1;i <= m;i++){
		for(int j = 0;j <= d;j++) vis[i][j] = false,dis[i][j] = INT_MAX;
	}
}
void run(){
	init();
	int x,y;
	cin >> x >> y;
	if(m <= 1000 && f[x][y] != -1){
		cout << f[x][y] + w[x] + w[y];
		return;
	}
	vis[x][0] = true;
	dis[x][0] = 0;
	priority_queue<pair<int,pair<int,int>> > q;
	q.push({0,{x,0}});
	while(!q.empty()){
		auto p = q.top();
		q.pop();
		int rx = p.second.first,pos = p.second.second;
		for(auto k : v[rx][pos]){
			int ry = k.first.first,t = k.first.second,w = k.second;
			if(vis[ry][t]) continue;
			vis[ry][t] = true;
			if(dis[rx][pos] + w < dis[ry][t]){
				dis[ry][t] = dis[rx][pos] + w;
				q.push({-dis[ry][t],{ry,t}});
			}
		}
	}
	if(m <= 1000){
		for(int i = 1;i <= n;i++){
			f[i][x] = f[x][i] = dis[i][0];
		}
	}
	cout << dis[y][0] + w[x] + w[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
		unuse[i] = 1;
	}
	if(m <= 1000){
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= m;j++) f[i][j] = -1;
		}
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		int x,t;
		cin >> x >> t;
		v[x][unuse[x]].push_back({{x,0},t});
		v[x][0].push_back({{x,unuse[x]},t});
		int lstuse = unuse[x],pre = x;
		unuse[x]++;
		for(int i = 2;i <= k;i++){
			cin >> x >> t;
			v[pre][lstuse].push_back({{x,unuse[x]},0});
			v[x][unuse[x]].push_back({{pre,lstuse},0});
			v[x][unuse[x]].push_back({{x,0},t});
			v[x][0].push_back({{x,unuse[x]},t});
			lstuse = unuse[x];
			pre = x;
			unuse[x]++;
		}
	}
	while(q--){
		run();
		cout << endl;
	}
	return 0;
}

