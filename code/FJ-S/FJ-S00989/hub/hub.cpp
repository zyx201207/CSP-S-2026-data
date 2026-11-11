#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=105;

int n,k,mi;
vector<int> e[N];
int mp[N][N],dep[N],f[N],d[N],vis[N];

int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void dfs(int u,int fa)
{
	if(vis[u]) mi=min(mi,dep[u]);
	for(auto v:e[u]){
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		mp[u][v]=mp[v][u]=1;
	}
	int ans=1e9;
	for(int i=0;i<(1<<n);i++){
		int cnt=0;
		for(int j=1;j<=n;j++) vis[j]=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				d[++cnt]=j;
				vis[j]=1;
			}
			f[j]=j;
		}
		if(cnt!=k) continue;
		for(int j=1;j<=cnt;j++){
			for(int kk=1;kk<j;kk++){
				int u=d[j],v=d[kk];
				if(mp[u][v]){
					u=find(u);v=find(v);
					if(u!=v) f[v]=u;
				}
			}
		}
		int kuai=0;
		for(int j=1;j<=cnt;j++){
			if(f[d[j]]==d[j]) kuai++;
		}
		if(kuai>2) continue;
		int mx=0;
		for(int j=1;j<=n;j++){
			mi=1e9;
			dep[j]=0;
			dfs(j,0);
			mx=max(mx,mi);
		}
		ans=min(ans,mx);
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		e[i].clear();
		for(int j=1;j<=n;j++) mp[i][j]=0;
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}

