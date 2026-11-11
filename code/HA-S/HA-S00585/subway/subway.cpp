#include<bits/stdc++.h>
using namespace std;
int c;
int n,m,d,q;
long long mi;
bool vis[500005];
int w[500005];
bool f[505][500005];
int ti[505][500005];
void dfs(int x,int y,long long time) {
	if (time>=mi) return;
	if (x==y) {
		mi=min(mi,time);
		return;
	}
	for (int i=1; i<=n; i++) {
		if (!f[i][x]) continue;
		for (int j=1; j<=m; j++) {
			if (j==x || !f[i][j] || vis[j]) continue;
			vis[j]=true;
			dfs(j,y,time+ti[i][x]+ti[i][j]);
			vis[j]=false;
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n>>m>>d>>q;
	for (int i=1; i<=m; i++) cin>>w[i];
	for (int i=1; i<=n; i++) {
		int k;
		cin>>k;
		if (k==1) continue;
		for (int j=1; j<=k; j++) {
			int a,t;
			cin>>a>>t;
			f[i][a]=true;
			ti[i][a]=t;
		}
	}
	while (q--) {
		int x,y;
		cin>>x>>y;
		mi=1e9;
		memset(vis,false,sizeof(vis));
		vis[x]=true;
		dfs(x,y,0);
		cout<<mi+w[x]+w[y]<<endl;
	}
	return 0;
}
