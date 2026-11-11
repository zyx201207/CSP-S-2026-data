#include<bits/stdc++.h>
using namespace std;
int T,n,k,fa[20],dep[20],c,vis[20];
vector<int>g[20];
void dfs(int x,int ff){
	fa[x]=ff;dep[x]=dep[ff]+1;
	for(int i=0;i<g[x].size();i++){
		int v=g[x][i];
		if(v==ff)continue;
		dfs(v,x);
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int qwq=dep[y]-dep[x];
	while(qwq--)y=fa[y];
	if(x==y)return x;
	while(x!=y)x=fa[x],y=fa[y];
	return x;
}
void dfs2(int x,int qwq){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int v=g[x][i];
		if(vis[v]||(qwq&(1<<(v-1)))==0)continue;
		dfs2(v,qwq); 
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0); 
		int ans=1e9;
		for(int i=0;i<(1<<n);i++){
			int cnt=0,cnt1=0,qwq=0,res=0;
			for(int j=0;j<n;j++)cnt+=((i&(1<<j))==(1<<j));
			for(int j=1;j<=n;j++)vis[j]=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))&&!vis[j]){
					dfs2(j,i);
					cnt1++;
				}
			}
			if(cnt!=k||cnt1>2)continue;
			for(int j=1;j<=n;j++){
				res=1e9;
				for(int l=1;l<=n;l++){
					if(i&(1<<(l-1)))res=min(res,dep[j]+dep[l]-2*dep[lca(j,l)]);
				}
				qwq=max(qwq,res);
			}
			ans=min(ans,qwq);
			//if(qwq==1)cout<<i<<"\n";
		}
		cout<<ans<<"\n"; 
	}
	return 0;
}
//100+100+0+15=225?
//话说不会挂一堆分吧 
