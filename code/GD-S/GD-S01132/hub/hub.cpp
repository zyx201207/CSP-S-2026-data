#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k;
vector<int> g[15];
int vis[15];
int fa[15];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
void unionn(int u,int v){
	int fu=find(u),fv=find(v);
	if(fu==fv) return;
	fa[fu]=fv;
}
bool viss[15];
int CTT=1e8;
int ans=1e8;
void dfs1(int kk,int dist){
	viss[kk]=1;
	if(vis[kk]){
		CTT=min(CTT,dist);
		return;
	}
	for(int i=0;i<g[kk].size();i++){
		int v=g[kk][i];
		if(viss[kk]==true) continue;
		dfs1(kk,dist+1);
	}
}
void dfs(int kk){
	if(kk==6) {
		init();
		for(int i=1;i<=n;i++){
			for(int j=0;j<g[i].size();j++){
				if(vis[i]==true&&vis[g[i][j]]==true){
					unionn(i,g[i][j]);
				}
			}
		}
		set<int> st;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				st.insert(find(i));
			}
		}
		if(st.size()>2) {
			return;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==true) sum=max(sum,0);
			CTT=1e8;
			memset(viss,0,sizeof(viss));
			dfs1(i,0);
			sum=max(sum,CTT);
		}
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==true) continue;
		vis[i]=true;
		dfs(kk+1);
		vis[i]=false;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e8;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
} 
