#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> edge[2000010];
int n,k;
int s;
int dis[2000010];

void dfs(int u,int fa){
	for(int v:edge[u]){
		if(v==fa) continue;
		if(dis[v]) continue;
		dis[v] = dis[u]+1;
		dfs(v,u);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		s=1;
		for(int i=1;i<n;++i){
			int u,v;cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		memset(dis,0,sizeof(dis));
		dfs(s,0);
		for(int i=1;i<=n;++i){
			if(dis[i]>dis[s]) s=i;
		}
		memset(dis,0,sizeof(dis));
		dfs(s,0);
		for(int i=1;i<=n;++i){
			if(dis[i]>dis[s]) s=i;
		}
		cout<<dis[s]<<"\n";
	}


	return 0;
}

