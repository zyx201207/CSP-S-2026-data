#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int N = 1000005;
int c,t;
vector<int> edge[N];
int n,k;
int dep[N],f[N][21],siz[N];
int G1,G2;
void dfs(int u,int fa){
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	siz[u] = 1;
	for(int i = 1;i <= __lg(n);i++) f[u][i] = f[f[u][i-1]][i-1];
	int mx = 0;
	for(auto v : edge[u]){
		if(v == fa) continue;
		dfs(v,u);
		siz[u] += siz[v];
		mx = max(mx,siz[v]);
	}
	mx = max(mx,n - siz[u]);
	if(mx <= (n >> 1)){
		if(G1) G2 = u;
		else G1 = u;
	}
}
int lca(int u,int v){
	if(dep[u] < dep[v]) swap(u,v);
	for(int i = __lg(n);i >= 0;i--) if(dep[f[u][i]] >= dep[v]) u = f[u][i];
	if(u == v) return u;
	for(int i = __lg(n);i >= 0;i--) if(f[u][i] != f[v][i]) u = f[u][i],v = f[v][i];
	return f[u][0];
}
int dist(int u,int v){ return dep[u] + dep[v] - (dep[lca(u,v)] << 1); }
int minn = 2e9;
int col[N],fa[N];
int find(int x){ return x == fa[x]? x : (fa[x] = find(fa[x])); }
void merge(int x,int y){ x = find(x),y = find(y);fa[x] = y; }
int ge[N][2],di[N][2];
void work(){
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= n;i++) if(col[i]) for(auto j : edge[i]) if(col[j]) merge(i,j);
	int cnt = 0;
	for(int i = 1;i <= n;i++) if(col[i]) cnt += (fa[i] == i);
	if(cnt > 2) return ;
	int mx = 0;
	for(int i = 1;i <= n;i++){
		if(col[i]) continue;
		int mmn = 2e9;
		for(int j = 1;j <= n;j++){
			if(!col[j]) continue;
			mmn = min(mmn,dist(i,j));
		}
		mx = max(mx,mmn);
	}
	minn = min(minn,mx);
}
void ddfs(int step,int cnt){
	if(cnt > k) return ;
	if(step == n + 1){
		if(cnt == k) return work();
		return ;
	}
	for(int i = 0;i <= 2;i++){
		col[step] = i;
		ddfs(step + 1,cnt + (i > 0));
		col[step] = 0;
	}
}
void brute(){
	minn = 2e9;
	ddfs(1,0);
	cout << minn << '\n';
}
int X[N],Y[N];
void solve(){
	cin >> n >> k;
	for(int i = 1,u,v;i < n;i++){
		cin >> u >> v;X[i] = u,Y[i] = v;
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}
	dfs(1,0);
	if(n <= 10) return brute();
	else if(c == 13 || c == 14){
		int up = (n + 1 >> 1);
		cout << (up + k) / (k + 1);
	}
	// else if(k == 2){
		// for(int i = 1;i <= n;i++) ge[i][0] = ge[i][1] = i,di[i][0] = di[i][1] = 0,fa[i] = i;
		// for(int i = 1;i < n;i++){
			// int r1 = find(X[i]),r2 = find(Y[i]);
			// int mn = 2e9,pd1 = 0,pd2 = 0,pg1 = 0,pg2 = 0;
			// for(int j = 0;j <= 1;j++)
				// for(int kk = 0;kk <= 1;kk++){
					// int nd1 = max(di[r1][j],1 + di[r2][kk]),nd2 = max(di[r2][kk],1 + di[r1][j]);
					// if(max(nd1,nd2) < mn){
						// mn = max(nd1,nd2);
						// pd1 = nd1,pd2 = nd2;
						// pg1 = ge[r1][j],pg2 = ge[r2][kk];
					// }
				// }
			// fa[r1] = r2;
			// ge[r2][0] = pg1,ge[r2][1] = pg2;
			// di[r2][0] = pd1,di[r2][1] = pd2;
		// }
		// cout << max(di[find(1)][0],di[find(1)][1]) << '\n';
	// }
}
void clear(){
	for(int i = 1;i <= n;i++)
		edge[i].clear();
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin >> c >> t;
	while(t--) solve(),clear();
	
	return 0;
}