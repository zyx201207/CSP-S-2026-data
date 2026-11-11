#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

vector<int> g[N];
int n, k, ans = 1e9;
bool flag[N];

int dis;
bool vis[N];
int dfs(int u, int fa, int k){
	if(flag[u]){
		return k;
	}
	int d = 1e9;
	for(auto v : g[u]){
		if(v == fa)continue;
		d = min(d, dfs(v, u, k + 1));
	}
	return d;
}

void dfs2(int u, int fa){
	vis[u] = 1;
	for(auto v : g[u]){
		if(v == fa || !flag[v])continue;
		dfs2(v, u);
	}
}



void dfs(int x, int k){
	if(x > n){
		memset(vis, 0, sizeof vis);
		int t = 0;
		for(int i = 1; i <= n; i++){
			if(!vis[i] && flag[i]){
				t++;
			}
		}
		if(t > 2)return;
		
		int res = 0;
		//for(int i = 1; i <= n; i++)cout << flag[i] << " ";
		//cout << '\n';
		for(int i = 1; i <= n; i++){
			res = max(res, dfs(i, 0, 0));
			//cout << i << " " << dfs(i, 0, 0) << '\n';
		}
		//cout << res << '\n';
		ans = min(ans, res);
		return;
	}
	
	if(k > 0){
		flag[x] = 1;
		dfs(x + 1, k - 1);
		flag[x] = 0;
	}
	
	dfs(x + 1, k);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		ans = 1e9;
		cin >> n >> k;
		for(int i = 0; i <= 1e5; i++)g[i].clear();
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		dfs(1, k);
		
		cout << ans << '\n';
		
	}
}

/*

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
