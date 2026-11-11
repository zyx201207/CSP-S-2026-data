#include<bits/stdc++.h>
using namespace std;
int v[501][501],w[200001],fa[200001],vis[200010];
vector<int>G[200001];
//set<int>et[200001];
int n,m,c,d,q,ans;
int stm,enm;
void dfs(int st,int en,int take){
	vis[st]=1;
	if(st==en){
		ans=min(ans,take);
		return;	
	}
	for(auto e:G[st]){
		if(e==fa[st])continue;
		if(vis[e]==0){
			if(fa[st]==0&&st!=stm){
				dfs(e,en,take+v[1][1]*2);
			}
		}
	}
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int pre=0;
		for(int j=1;j<=2*k;j++){
			int u;
			cin>>u;
			G[pre].push_back(u);
			G[u].push_back(pre);
		if(!fa[u])fa[u]=pre;
		else fa[u]=0;
			pre=u;
			cin>>v[j][k];
		}
		
	}
	for(int i=1;i<=q;i++){
		
		cin>>stm>>enm;
		ans=0;
		memset(vis,0,sizeof vis);
		dfs(stm,enm,w[stm]+w[enm]+v[1][1]*2);
		cout<<ans<<'\n';
	}
//	fclose(stdin);
//	fclose(stdout);
}
