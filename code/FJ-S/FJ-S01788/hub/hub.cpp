#include<bits/stdc++.h>
using namespace std;

inline int qread(){
	int x = 0;
	char c = getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar()) x = x*10+c-48;
	return x;
}

const int LOG = 20;

int n, k;
vector<int> dep;
vector<vector<int>> up, graph;


void dfs_initlca(int u, int fa){
	dep[u] = dep[fa] + 1;
	up[u][0] = fa;
	for(int i = 1; i<LOG; i++) up[u][i] = up[ up[u][i-1] ][i-1];
	for(int v: graph[u]){
		if(v!=fa){
			dfs_initlca(v, u);
		}
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	int diff = dep[x] - dep[y];
	for(int i = 0; i<LOG; i++){
		if(diff & (1 << i)) x = up[x][i];
	}
	if(x == y) return x;
	for(int i = LOG - 1; i>=0; i--){
		if(up[x][i] != up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}

int dist(int x, int y){
	int sf = lca(x, y);
	return dep[x] - dep[sf] + dep[y] - dep[sf];
}

void process(){
	n = qread(); k = qread();
	graph.clear();
	dep.clear();
	up.clear();
	graph.resize(n+1);
	for(int i = 0; i<n-1; i++){
		int u = qread(), v = qread();
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dep.resize(n+1, 0);
	up.resize(n+1, vector<int>(LOG+1));
	dfs_initlca(1, 0);
	
	int maxn = 0;
	for(int mask = 0; mask<n; mask++){
		vector<int> idx;
		for(int i = 0; (1 << i) <= mask; i++){
			if(mask & 1) idx.push_back(i);
		}
		if(idx.size() != k) continue;

		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				bool continue_flag = false;
				for(int _ = 0; _ < k; _++){
					if(idx[_] == i || idx[_] == j){
						continue_flag = true;
						break;
					}
				}
				if(continue_flag) continue;
				maxn = max(maxn, dist(i, j));
			}
		}
	}
	
	printf("%d", maxn);
}



int main(){
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c = qread(), t = qread();
	while(t--) process();
	return 0;
}