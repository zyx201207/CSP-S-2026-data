#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int c,t,n,k;
vector<int> g[1000005];
int dep[1000005];
int maxx,idx,kkk;
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>maxx){
		maxx=dep[u];
		idx=u;
	}
	for(int i=0;i<g[u].size();i++){
		dfs(g[u][i],u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		maxx=0;
		kkk=idx;
		dfs(kkk,0);
		cout<<(maxx-1)/2<<endl;
	}
	return 0; 
} 
