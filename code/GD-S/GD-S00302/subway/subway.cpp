#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500 + 5;
struct edge{
	int to , t;
};
vector<edge> g[N];
int w[N];
int c , n , m , d , q;
int ans;
int vis[N] ;
int b[N];
void dfs(int now , int goal , int time , int c[]){
	vis[now] = 1 ;
	if(now == goal){
		ans = min(time , ans);
		return;
	}
	for(int i = 0 ; i < g[now].size(); i++){
		edge tt = g[now][i];
		c[i] += 1;
		if(c[i] > d){
			return ;
		}
		if(vis[tt.to ] == 0){
			dfs(tt.to , goal , time + tt.t ,c);
			vis[tt.to] = 0;
		}
	}
}
signed main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++){
		cin >> w[i];
	}
	for(int i = 1 ; i <= n ; i++ ){
		int k;
		cin >> k;
		for(int j = 1;j <= k ; j++){
			int u , v;
			cin >> u >> v;
			g[i].push_back({u , v});
		}
		
	}
	while(q--){
		ans =1e9;
		int x , y;
		cin >> x >> y;
		dfs(x , y , w[x] + w[y], b);
		cout <<ans <<endl;
	}
	return 0;
} 
