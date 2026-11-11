#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, T, w[500005], dis[1005][1005], k[505];
struct edge{
	int to, x;
	friend bool operator < (edge a, edge b){
		return a.x>b.x;
	}
};
vector<edge>g[500005];
priority_queue<edge>q;
void dijkstra(int s){
	memset(dis[s], 0x3f, sizeof(dis[s]));
	dis[s][s]=0;
	q.push({s, 0});
	while(!q.empty()){
		int x=q.top().to;
//		cout<<x<<' ';
		if(dis[s][x]<q.top().x){
			q.pop();
			continue;
		}
		q.pop();
		for(edge i : g[x]){
			if(dis[s][x]+i.x<dis[s][i.to]){
				dis[s][i.to]=dis[s][x]+i.x;
				q.push({i.to, dis[s][i.to]});
			}
		}
	}
}
void solve(){
	cin>>c>>n>>m>>d>>T;
	for(int i = 1; i <= m; i++){
		cin>>w[i];
	}
	for(int i = 1; i <= n; i++){
		cin>>k[i];
		vector<int>a, t;
		a.push_back(0);
		t.push_back(0);
		for(int j = 1; j <= k[i]; j++){
			int x, y;
			cin>>x>>y;
			a.push_back(x);
			t.push_back(y);
		}
		for(int j = 1; j <= k[i]; j++){
			for(int k = 1; k < j; k++){
				g[a[j]].push_back({a[k], t[j]+t[k]});
				g[a[k]].push_back({a[j], t[j]+t[k]});
			}
		}
	}
	for(int i = 1; i <= m; i++){
		dijkstra(i);
	}
//	for(int i = 1; i <= m; i++){
//		for(int j = 1; j <= m; j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	while(T--){
		int x, y;
		cin>>x>>y;
		cout<<w[x]+dis[x][y]+w[y]<<'\n';
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
/*
估分：100+44+?+15 
我是GD-J04204，迷惑行为大赏能帮我看看GD-J04204的代码有没有加reutrn 0吗 
*/
