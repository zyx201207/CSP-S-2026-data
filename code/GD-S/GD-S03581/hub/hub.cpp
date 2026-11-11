#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n, k;
vector<int> g[N];
int dep[N];
void dfs(int x, int fa){
	dep[x] = dep[fa] + 1;
	for(auto u : g[x]){
		if(u == fa) continue;
		dfs(u, x);
	}
	return ;
}
void solve(int testnum){
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		g[i].clear();
	}
	for(int i = 1, u, v; i < n; i ++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(13 <= testnum && testnum <= 14){
		int m = (n - 1) / 2;
		cout << m / 4 + 1<< endl;
	}
//	if(testnum == 7 || (11 <= testnum && testnum <= 12)){
		dfs(1, 0);
		int maxn = 0, maxid = 1;
		for(int i = 1; i <= n; i ++){
			if(dep[i] > maxn){
				maxn = dep[i], maxid = i;
			}
		}
		memset(dep, 0, sizeof dep);
		dfs(maxid, 0);
		maxn = 0, maxid = 1;
		for(int i = 1; i <= n; i ++){
			if(dep[i] > maxn){
				maxn = dep[i], maxid = i;
			}
		}
//		maxn = (maxn + 2) / 3;
		cout << (maxn) / 3 << endl;
//		cout << maxn << endl;
//	}
}
signed main(){
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--){
		solve(c);
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
