#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#define PU push_back
#define ll long long
using namespace std;
const int inf = 1e9;
const int N = 1e5 + 5;
int C, T, n, k, cho[N], d[N], ans;
vector<int> g[N];
bool vis[N], vis1[N];

void init(){
	ans = inf;
	for(int i = 1; i <= n; ++i) g[i].clear();
	memset(vis, 0, sizeof vis);
	memset(vis1, 0, sizeof vis1);
	memset(d, 0, sizeof d);
}

void DFS1(int u, int fr){
	vis1[u] = 1;
	for(int v : g[u]){
		if(v == fr || !vis[v]) continue;
		DFS1(v, u);
	}
}

bool check(){
	memset(vis1, 0, sizeof vis1);
	
	int cnt = 0;
	for(int i = 1; i <= k; ++i){
		if(!vis1[cho[i]]){
			++cnt;
			DFS1(cho[i], 0);
		}
	}
	return cnt <= 2;
}

void DFS2(int u, int fr){
	d[u] = d[fr] + 1;
	for(int v : g[u]){
		if(v == fr) continue;
		DFS2(v, u);
	}
}

void DFS(int x, int lst){
	if(x == k + 1){
		if(check()){
//			cout << "cho:";
//			for(int i = 1; i <= k; ++i) cout << cho[i] << ' ';
			int bj = 0;
			for(int i = 1; i <= n; ++i){
				if(!vis[i]){
					DFS2(i, 0);
					int jl = inf;
					for(int j = 1; j <= k; ++j){
						jl = min(jl, d[cho[j]] - 1);
					}
					bj = max(bj, jl);
				}
			}
//			cout << "bj:" << bj << '\n';
			ans = min(ans, bj);
		}
		return;
	}
	
	for(int i = lst + 1; i <= n; ++i){
		cho[x] = i;
		vis[i] = 1;
		DFS(x + 1, i);
		vis[i] = 0;
	}
}

void solve(){
	cin >> n >> k;
	init();
	
	for(int i = 1, u, v; i < n; ++i){
		cin >> u >> v;
		g[u].PU(v), g[v].PU(u);
	}
	
	DFS(1, 0);
	
	cout << ans << '\n';
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> C >> T;
	while(T--) solve();
	return 0;
}
