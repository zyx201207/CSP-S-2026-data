#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a,t;
}b[500050];
int c,n,m,d,q,w[500050],k;
long long ans=0x3f3f3f3f;
bool vis[500050];
vector<stu> g[500050];
vector<stu> e[500050];
void dfs(int id,long long T,int y){
	vis[id]=1;
	if(id==y){
		ans=min(ans,T);
		return;
	}
    for(int i=0;i<g[id].size();i++){
		if(!vis[g[id][i].a]){
			for(int j=0;j<e[g[id][i].a].size();j++){
				if(!vis[e[g[id][i].a][j].a]){
					dfs(e[g[id][i].a][j].a,T+e[g[id][i].a][j].t+g[id][i].t,y);
					vis[e[g[id][i].a][j].a]=0;
				}
			}
			vis[g[id][i].a]=0;
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
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[i].push_back({a,t});
			e[a].push_back({i,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dfs(x,w[x],y);
		cout<<ans+w[y]<<endl;
		ans=0x3f3f3f3f;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}

