//16 pts
#include<bits/stdc++.h>
using namespace std;
int ans,sum;
bool use[25],vis[25];
int dist[25][25];
int n,k;
vector <int> g[25];
void dfs(int x,int fa) {
	if (!use[x]) return;
	use[x] = 0;
	sum--;
	for (int i = 0;i<g[x].size();i++) {
		int y = g[x][i];
		if (y!=fa) dfs(y,x);
	}
}
bool check() {
	sum = 0;
	for (int i = 1;i<=n;i++)
		if (use[i]) sum++;
	if (sum!=k) return 0;
	int cnt = 0;
	for (int i = 1;i<=n;i++) {
		int la = sum;
		dfs(i,0);
		if (la!=sum) cnt++;
		if (cnt>2) return 0;
		if (sum==0) return 1;
	}
	return 1;
}
int getd() {
	vector <int> pub;
	int re1 = 0;
	for (int i = 1;i<=n;i++)
		if (vis[i])
			pub.push_back(i);
	for (int i = 1;i<=n;i++) {
		int re = 2147483647;
		for (int j = 0;j<pub.size();j++)
			re = min(re,dist[i][pub[j]]);
		re1 = max(re,re1);
	}
	return re1;
}
void solve() {
	for (int i = 1;i<=20;i++) g[i].clear();
	ans = 2147483647;
	memset(dist,0x3f,sizeof dist);
	cin>>n>>k;
	if (k==2) {
		for (int i = 1;i<n;i++) {
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			dist[u][v] = dist[v][u] = 1;
		}
		for (int i = 1;i<=n;i++) dist[i][i] = 0;
		for (int i = 1;i<=n;i++)
			for (int j = 1;j<=n;j++)
				if (i!=j)
					for (int k = 1;k<=n;k++)
						if (i!=k&&j!=k)
							dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
		for (int i = 1;i<=n;i++)
			for (int j = i+1;j<=n;j++) {
				memset(use,0,sizeof use);
				memset(vis,0,sizeof vis);
				vis[i] = 1,vis[j] = 1;
				ans = min(ans,getd());
			}
		cout<<ans<<endl;
		return;
	}
	if (n>20) {
		cout<<"ERROR\n";
		return;
	}
	for (int i = 1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		dist[u][v] = dist[v][u] = 1;
	}
	for (int i = 1;i<=n;i++) dist[i][i] = 0;
	for (int i = 1;i<=n;i++)
		for (int j = 1;j<=n;j++)
			if (i!=j)
				for (int k = 1;k<=n;k++)
					if (i!=k&&j!=k)
						dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
	for (int i = 0;i<(1<<n);i++) {
		int k = i;
		memset(use,0,sizeof use);
		memset(vis,0,sizeof vis);
		int now = 1;
		while (k>0) {
			int q = k%2;
			if (q==1) use[now] = vis[now] = 1;
			now++;
			k/=2;
		}
		if (check()) ans = min(ans,getd());
	}
	cout<<ans<<endl;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--) solve();
}
