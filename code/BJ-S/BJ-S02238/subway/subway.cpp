#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
using namespace std;
const int N = 505;
int c, n, m, dd, qq, cnt;
ll w[500005];
struct Edge{
	int to;ll diss;
	friend bool operator < (Edge a, Edge b){return a.diss > b.diss;}
};
struct node{
	int id;ll diss;
	friend bool operator < (node a, node b){return a.diss > b.diss;}
};
vector<Edge> e[500005];
vector<pair<int, ll> > a[25];//the ith line comes through
ll dis[500005];//zui duan lu
bool flag[500005];
priority_queue<node> q;
map<pair<int, int>, ll> ans;
void Dijkstra(int s){
	for(int i = 1; i <= cnt; i++)dis[i] = 1145141919810, flag[i] = 0;
	dis[s] = 0;
	q.push({s, 0});
	while(!q.empty()){
		int u = q.top().id;
		q.pop();
		if(flag[u]){continue;}// yi jing qiu de
		flag[u] = 1;
		for(int i = 0; i < (int)e[u].size(); i++){
			int v = e[u][i].to;ll d = e[u][i].diss;
			if(flag[v]){continue;}
			if(dis[v] > dis[u] + d){
				dis[v] = dis[u] + d;
				q.push({v, dis[v]});
			}
		}
	}
	for(int i = 1; i <= cnt; i++){
		ans[{s, i}] = ans[{i, s}] = dis[i];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> dd >> qq;
	rep(i, 1, m)cin >> w[i];
	rep(i, 1, n){
		int k;cin >> k;
		rep(j, 1, k){
			int x;ll t;cin >> x >> t;
			a[i].push_back({x, t});
		}
	}
	//kaishi jian tu
	cnt = m;
	for(int i = 1; i <= n ;i++){
		for(int j = 0; j < (int)a[i].size(); j++){
			int v = a[i][j].first, dis = a[i][j].second;
			e[v].push_back({++cnt, dis});//zhanting yu zhantai
			e[cnt].push_back({v, dis});
			a[i][j].first = v = cnt;
			if(j != 0){
				e[v].push_back({a[i][0].first, 0});//xian lu nei bu de zhantai
				e[a[i][0].first].push_back({v, 0});//xian lu nei bu de zhantai
			}
		}
	}
	rep(i, 1, qq){
		int u, v;
		cin >> u >> v;
		if(!ans[{u, v}] || !ans[{v, u}]){
			Dijkstra(u);
		}
		cout << ans[{u, v}] + w[u] + w[v] << '\n';
	}
	return 0;
}
