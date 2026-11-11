#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int n,m,T,c;
int p[N],dep[N],dp[N][26];
vector<int> g[N],o;
bool ok[N];
int find(int u){
	if(p[u]==u) return u;
	return p[u]=find(p[u]);
}
void dfs1(int u,int fa){
	for(int v:g[u]){
		if(v==fa||!ok[v]) continue;
		p[find(v)]=find(u);
		dfs1(v,u);
	}
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	dp[u][0]=fa;
	for(int i=1;i<=25;i++){
		dp[u][i]=dp[dp[u][i-1]][i-1];
	}
	for(int v:g[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=25;i>=0;i--){
		if(dep[dp[x][i]]>=dep[y]) x=dp[x][i];
	}
	if(x==y) return x;
	for(int i=25;i>=0;i--){
		if(dp[x][i]!=dp[y][i]){
			x=dp[x][i];
			y=dp[y][i];
		}
	}
	return dp[x][0];
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		int ans=1e9;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);
		for(int lel=1;lel<(1<<n);lel++){
			o.clear();
			int cnt=0;
			for(int i=1;i<=n;i++){
				p[i]=i;
				if(lel&(1<<(i-1))) cnt++,ok[i]=1,o.push_back(i);
				else ok[i]=0;
			}
			if(cnt>m) continue;
			for(int i=1;i<=n;i++){
				if(!ok[i]||p[i]!=i) continue;
				dfs1(i,0);
			}
			cnt=0;
			for(int i=1;i<=n;i++) if(ok[i]&&p[i]==i) cnt++;
			if(cnt>2) continue;
			int res=0;
			for(int i=1;i<=n;i++){
				int tmp=1e9;
				for(int l:o){
					int LCA=lca(i,l);
					int dis=dep[l]+dep[i]-2*dep[LCA];
					tmp=min(tmp,dis);
				}
				res=max(res,tmp);
			}
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
