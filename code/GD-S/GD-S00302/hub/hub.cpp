#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
vector<int> g[N];
int ans , t;
void dfs(int x , int f , int step){
	ans = max(step , ans);
	for(int i = 0;i < g[x].size; i++){
		if(g[x][i] != f){
			dfs(g[x][i] ,x , step + 1  );
		}
	}
}
signed main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int c , t;
	cin >> c >> t;
	while(t--){
		ans = 0;
		int n , m;
		cin >> n >> m;
		for(int i = 1 ;i < n ; i++){
			int u , v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i = 1 ;i <= n ; i++){
			dfs(1 , 0 , 0);
		}
		cout<<ans / 2;
	}
	return 0;
} 
