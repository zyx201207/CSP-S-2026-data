#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,dis,ans,pos;
vector<int >e[2000001];
void dfs(int u,int fa){
	if(dis>ans){
		ans=dis;
		pos=u;
	}
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(fa==v)continue;
		dis++;
		dfs(v,u);
		dis--;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			e[i].clear();
			if(i<n){
				int u,v;
				cin>>u>>v;
				e[u].push_back(v);	
				e[v].push_back(u);
			}
		}
		int ans2;
	for(int i=1;i<=n;i++){
		dfs(i,0);
		ans2=min(ans,ans2);
	}
	cout<<ans2;
	
	return 0;
} 
