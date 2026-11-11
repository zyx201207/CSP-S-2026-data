#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
#define il inline
int c;
int n,k;
vector<int> e[N];
int mk[N];

int fa[N],dep[N];
void dfs(int u,int f){
	fa[u]=f; dep[u]=dep[f]+1;
	for(auto v:e[u]){
		if(v==f)continue;
		dfs(v,u);
	}
}

il int lca(int u,int v){
	if(u==v)return u;
	if(dep[u]<dep[v])swap(u,v);
	while(dep[u]>dep[v])u=fa[u];
	while(u!=v)u=fa[u],v=fa[v];
	return u;
}

il int run(){
	int mx=0;
	for(int i=1;i<=n;i++){
		if(mk[i]==1)continue;
		int mn=n+1;
		for(int j=1;j<=n;j++){
			if(mk[j]==1){
//				cout<<dep[i]<<" "<<dep[j]<<" "<<dep[lca(i,j)]<<'\n';
				mn=min(mn,dep[i]+dep[j]-2*dep[lca(i,j)]);
			}
		}
		mx=max(mx,mn);
	}
	return mx;
}

il void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	int ans=n+1;
	int S=(1<<n);
	for(int s=1;s<S-1;s++){
		for(int i=0;i<n;i++){
			if(s&(1<<i))mk[i+1]=1;
			else mk[i+1]=0;
//			cout<<mk[i+1]<<" ";
		}
//		cout<<'\n';
//		cout<<": "<<run()<<'\n';
		ans=min(ans,run());
	}
	cout<<ans;
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t; cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5


*/
