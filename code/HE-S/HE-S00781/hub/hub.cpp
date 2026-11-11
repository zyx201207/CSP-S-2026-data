#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;

int c, t, n, k, dis[15][15], vis[N];
vector<int> e[N];
void dfs1(int ro, int u, int fa){
	if(fa) dis[ro][u] = dis[ro][fa] + 1;
	for(auto v : e[u]){
		if(v == fa) continue;
		dfs1(ro, v, u);
	}
}

void dfs2(int u, int fa, int s){
	vis[u] = 1;
	//cout << u << '\n';
	for(auto v : e[u]){
		if(v == fa || !(s & (1 << (v - 1)))) continue;
		dfs2(v, u, s);
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1, u, v;i < n;i++){
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i = 1;i <= n;i++){
			dfs1(i, i, 0);
//			for(int j = 1;j <= n;j++){
//				cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
//			}
		}
		int ans = 1e9;
		for(int i = 0;i < (1 << n);i++){
			int num = __builtin_popcount(i);
			if(num != k) continue;
			int sz = 0;
			for(int j = 1;j <= n;j++){
				if(!vis[j] && (i & (1 << (j - 1)))){
					//cout << "j: " << i << ' ' << j << '\n';
					dfs2(j, 0, i);
					sz++;
				}
			}
			for(int j = 1;j <= n;j++) vis[j] = 0;
			if(sz > 2) continue;
			
			int maxx = 0;
			for(int j = 1;j <= n;j++){
				if(i & (1 << (j - 1))) continue;
				int minn = 1e9;
				for(int k = 1;k <= n;k++){
					if(!(i & (1 << (k - 1)))) continue;
					minn = min(minn, dis[j][k]);
				}
				maxx = max(maxx, minn);
			}
			ans = min(maxx, ans);
		}
		cout << ans << '\n';
		
		for(int i = 1;i <= n;i++){
			e[i].clear();
			for(int j = 1;j <= n;j++){
				dis[i][j] = 0;
			}
		}
	}
	return 0;
}
/*

*/
