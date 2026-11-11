#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,k,dep[100005];
vector<int>g[100005];
void dfs(int d,int fa){
	dep[d] = dep[fa]+1;
	for (int i = 0; i < g[d].size(); i++){
		if (g[d][i] == fa) continue;
		dfs(g[d][i],d);
	}
}
int main(){
	freopen("hug.in","r",stdin);
	freopen("hug.out","w",stdout);
	cin >> c >> t;
	while (t--){
		long long ans = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i < n; i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dep[0] = 0;
		dfs(1,0);
		int num = 0,id;
		for (int i = 1; i <= n; i++){
			if (num < dep[i]){
				id = i;
				num = dep[i];
			}
		}
		dfs(id,0);
		for (int i = 1; i <= n; i++){
			if (num < dep[i]){
				id = i;
				num = dep[i];
			}
		}
		ans = (num-k)/3;
		if ((num-k) % 3) ans++;
		cout << ans <<"\n";
	}
	return 0;
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
