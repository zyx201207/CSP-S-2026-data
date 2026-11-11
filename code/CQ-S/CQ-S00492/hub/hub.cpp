#include <bits/stdc++.h>
#define int long long
#define maxn 15
using namespace std;
bool st;
int T,n,k,x,ans,y,fa[maxn],dist[maxn][maxn],dep[maxn];
bitset<maxn> vis;
vector<int> v[maxn];
void init(int x,int y){
	dep[x] = dep[y]+1,fa[x] = y;
	for (int i : v[x]) if (i != y) init(i,x);
}
int lca(int x,int y){
	if (dep[x] < dep[y]) swap(x,y);
	while (dep[x] > dep[y]) x = fa[x];
	while (x != y) x = fa[x],y = fa[y];
	return x;
}
int getans(){
	int ans = 0;
	for (int i = 1;i <= n;i++){
		int tmp = 1e9;
		for (int j = 1;j <= n;j++){
			if (vis[j]) tmp = min(tmp,dist[i][j]); 
		}
		ans = max(ans,tmp);
	}
	return ans;
}
int check(int x,int y){
	int ans = vis[x];
	for (int i : v[x]){
		if (i == y) continue;
		ans += check(i,x)-(vis[x] && vis[i]);
	}
	return ans;
}
void dfs(int x,int y){
	if (x > n){
		if (y == k && check(1,0) <= 2)
			ans = min(ans,getans());
		return;
	}
	vis[x] = 0,dfs(x+1,y);
	if (y < k) vis[x] = 1,dfs(x+1,y+1);
}
bool en;
signed main(){
	#ifndef LOCAL
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	#endif
	cerr << (&en-&st)/1048576.0 << "\n";
	cin >> x >> T;
	while (T--){
		cin >> n >> k;
		for (int i = 1;i <= n;i++) v[i].clear();
		for (int i = 1;i < n;i++){
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		init(1,0);
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				dist[i][j] = dep[i]+dep[j]-2*dep[lca(i,j)];
		ans = 1e18,dfs(1,0);
		cout << ans << "\n";
	} 
	cerr << clock() << "\n";
	return 0;
}
