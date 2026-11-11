#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> G[N];
int n , k , maxn , dep[N] , fa[N];
deque<int> q;
void dfs1(int u , int f){
	dep[u] = dep[f] + 1;
	fa[u] = f;
	for(auto v : G[u]){
		if(f != v)dfs1(v , u);
	}
}
int lca(int x , int y){
//	cout << x << " " << y << endl;
	while(fa[x] != fa[y]){
//		cout << x << " " << endl;
		if(dep[fa[x]] < dep[fa[y]]) y = fa[y];
		else x = fa[x];
	}
	return fa[x];
}
void check(){
	if(q.size() != k) return ;
	vector<int> v;
	for(int i = 1 ; i <= k ; i++){
		v.push_back(q.front());
		q.push_back(q.front());
		q.pop_front();
	}
	int minn = 0;
	for(int i = 1 ; i <= n  ;i++){
//		cout << i << endl;
		for(auto k : v){
			minn = max(minn , dep[i] + dep[k] - 2 * dep[lca(i,k)]);
		}
		maxn = min(minn , maxn);
	}

}
void dfs(int cur){
//	cout << cur << endl;
	if(cur == n + 1){
		check();
		return;
//		cout << endl << endl;
	}
	q.push_back(cur);
	dfs(cur + 1);
	q.pop_back();
	dfs(cur + 1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c , T;
	cin >> c >> T;
	while(T--){
		cin >> n >> k;
		maxn = 10000000;
		for(int i = 1 ; i <= n ; i++){
			G[i].clear();
		}
		q.clear();
		for(int i = 1 ; i < n ; i++){
			int u , v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs1(1,1);
//		for(int i = 1 ; i <= n ; i++){
//			cout << dep[i] << " " << fa[i] << endl;
//		}
		dfs(1);
		cout << maxn << endl;
		
	}
}
