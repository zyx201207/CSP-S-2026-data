#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+5,INF=1e18;
struct node{
	int u,v,w;
}edge[N];
int c,n,m,d,q,w[N],idx,fa[N],f[N][30],sum[N][30],dep[N],dis[N];
bool vis[N];
vector<pair<int,int> > e[N];
bool cmp(node a,node b) {
	return a.w<b.w; 
}
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
} 
void dfs(int u,int fa,int VAL) {
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	sum[u][0]=VAL;
	for (int j=1;j<30;j++) {
		f[u][j]=f[f[u][j-1]][j-1];
		sum[u][j]=sum[u][j-1]+sum[f[u][j-1]][j-1];
	}
	for (auto V:e[u]) {
		int v=V.first,val=V.second;
		if (v==fa) continue;
		dfs(v,u,val);
	}
}
int lca(int x,int y) {
	if (dep[x]>dep[y]) swap(x,y);
	int ans=0;
	for (int j=29;j>=0;j--) {
		if (dep[f[y][j]]>=dep[x]) {
			ans+=sum[y][j];
			y=f[y][j];
		}
	}
	if (x==y) return ans;
	for (int j=29;j>=0;j--) {
		if (f[y][j]!=f[x][j]) {
			ans+=sum[y][j]+sum[x][j];
			x=f[x][j];
			y=f[y][j];
		}
	}
	ans+=sum[y][0]+sum[x][0];
	return ans;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++) {
		int k;
		cin>>k;
		for (int j=1;j<=k;j++) {
			int u,val;
			cin>>u>>val;
			if (c>15) edge[++idx]={u,m+i,val};
			else {
				e[m+i].push_back({u,val});
				e[u].push_back({m+i,val});
			}
		}
	}
	if (c<=15) {
		while (q--) {
			int x,y;
			cin>>x>>y;
			priority_queue<pair<int,int> > Q;
			for (int i=1;i<=n+m;i++) vis[i]=0;
			for (int i=1;i<=n+m;i++) dis[i]=INF;
			Q.push({0,x});
			dis[x]=0;
			while (!Q.empty()) {
				int u=Q.top().second,cnt=-Q.top().first;
				Q.pop();
				if (u==y) {
					cout<<w[x]+w[y]+cnt<<"\n";
					break;
				}
				if (vis[u]) continue;
				vis[u]=1;
				for (auto V:e[u]) {
					int v=V.first,val=V.second;
					if (dis[v]>cnt+val) {
						dis[v]=cnt+val;
						Q.push({-(cnt+val),v});
					}
				}
			} 
		}
	}else {
		sort(edge+1,edge+1+idx,cmp);
		for (int i=1;i<=m+n;i++) fa[i]=i;
		for (int i=1;i<=idx;i++) {
			int u=edge[i].u,v=edge[i].v,val=edge[i].w;
			int fu=find(u),fv=find(v);
			if (fu==fv) continue;
			fa[fu]=fv;
			e[u].push_back({v,val});
			e[v].push_back({u,val});
		}
		dfs(1,0,0);
		while (q--) {
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+lca(x,y)<<"\n";
		}
	}
	return 0;
}
