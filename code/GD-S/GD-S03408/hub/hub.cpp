# include <iostream>
# include <vector>
# include <set>
# define iL inline
# define ll long long
# define MULTEST
# define FILE
using namespace std;
const int N = 1e6 + 6,K = 1e6 + 6,N2 = 1e4 + 4,inf = N << 1;
int n,k,ans,a[K],pck[N],fa[N],dis[N2][N2]; vector<int> adj[N];
iL int findfa(int x){
	return (fa[x] == x ? x : fa[x] = findfa(fa[x]));
}iL void work(){
	for (int i = 1;i <= n;fa[i] = i,i++);
	for (int i = 1;i <= k;i++)
		for (int v : adj[a[i]])
			if (pck[v])
				fa[findfa(v)] = findfa(a[i]);
	set<int> st;
	for (int i = 1;i <= k;i++){
//		cerr << a[i] <<",";
		st.insert(findfa(a[i]));
		if (st.size() > 2) return;
	}int awa = 0;
	for (int i = 1,tot;i <= n;i++){
		if (pck[i]) continue;
		tot = inf;
		for (int j = 1;j <= k;j++)
			tot = min(tot,dis[i][a[j]]);
		awa = max(awa,tot);
	}ans = min(ans,awa);
//	cerr << ":" << awa << '\n';
}iL void dfs(int cnt,int lst){
	if (cnt == k) return work(),void();
	for (int i = lst + 1;i <= n - k + cnt + 1;i++)
		a[cnt + 1] = i,pck[i] = 1,
		dfs(cnt + 1,i),pck[i] = 0;
}iL void floyd(){
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
			dis[i][j] = dis[j][i] = inf;
	for (int i = 1;i <= n;i++)
		for (int v : adj[i])
			dis[i][v] = 1;
	for (int kk = 1;kk <= n;kk++)
		for (int i = 1;i <= n;i++)
			for (int j = i + 1;j <= n;j++)
				dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][kk] + dis[kk][j]);
}iL void solve(){
	cin >> n >> k;
	ans = inf;
	for (int i = 1;i <= n;i++)
		adj[i].clear();
	for (int i = 1,u,v;i < n;i++){
		cin >> u >> v;
		adj[u].push_back(v),
		adj[v].push_back(u);
	}floyd(),dfs(0,0);
	cout << ans << '\n';
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	# ifdef FILE
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	# endif
	int ___ = 1;
	# ifdef MULTEST
	cin >> ___ >> ___;
	# endif
	while (___--)
		solve();
	return 0;
}

