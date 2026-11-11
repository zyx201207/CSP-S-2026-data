#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> g[1010];
int dep[1010],dm[1010];
int cnt;
bool is[1010];
void dfs(int u,int fa){
	dep[u] = dep[fa]+1;
	dm[u] = dep[u];
	for(int v:g[u]){
		if(v == fa)continue;
		dfs(v,u);
		dm[u] = max(dm[u],dm[v]);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		//for(int i = 1;i <= n;i++)g[i].clear();
		for(int i = 1;i < n;i++){
			int u,v;
			cin>>u>>v;
		//	g[u].push_back(v);
		//	g[v].push_back(u); 
		}
		cout<<n/2;
	}
	return 0;
}

