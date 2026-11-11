#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500],t[500],v[500],ans;
struct edge{
	int u,v,w;
}a[505];
bool vis[505];
vector<edge>g[505];
vector<int>g2;
void dfs(int u,int e){
	if(u==e) return ;
	vis[u]=true;
	for(int i=1;i<=g[u].size();i++){
		int v=g[u][i].v;
		if(!vis[v]){
			ans+=g[u][i].w;
			g2.push_back(v);	
			dfs(v,e);
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int n2;
		cin>>n2;
		for(int j=1;j<=n2;j++){
			int u,w2;
			cin>>a[j].u>>a[j].w;
		}
		for(int j=1;j<n2;j++){
			g[a[j].u].push_back({a[j+1].u,a[j].w});
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		g2.clear();
		memset(vis,false,sizeof(vis));
		ans=0;
		dfs(s,e);
		for(int i=1;i<=g2.size();i++){
			ans+=w[g2[i]];
		} 
		cout<<ans<<endl;
	}
	return 0;
}
