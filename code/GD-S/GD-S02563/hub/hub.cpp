#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans,z[1000010],as[1000010],tmp[1000010],g[1000010],d[1000010];
vector<int>e[1000010],lf;
void dfs2(int u,int fa,bool fl){
	g[u]=1;if(e[u].size()<2||(fl&&e[u].size()==2))lf.push_back(u);
	for(int v:e[u])if(v!=fa)dfs2(v,u,0),d[u]++;
	if(!fl)d[u]++;
}
void solve(int u,int fa){
	for(int i=1;i<=n;i++)as[i]=z[i]=-1,g[i]=d[i]=0;
	lf.clear(),dfs2(u,fa,1);queue<int>q;
	for(auto it:lf)q.push(it),z[it]=1;
	int cnt=0;while(q.size()){
		int x=q.front();q.pop(),as[++cnt]=z[x];
		for(int v:e[x])if(g[v]&&z[v]==-1&&(--d[v])==1)z[v]=z[x]+1,q.push(v);
	}
	as[cnt]=1e9;
}
void dfs(int u,int fa){
	for(int v:e[u])if(v!=fa){
		solve(u,v),swap(as,tmp),solve(v,u);
		for(int i=0;i<=k;i++)if(as[i]!=-1&&tmp[k-i]!=-1)ans=min(ans,max(as[i],tmp[k-i]));
		dfs(v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>c>>t;while(t--){
		cin>>n>>k,k=n-k,ans=1e9;for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)e[i].clear();
	}
}
