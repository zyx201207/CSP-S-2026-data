#include<bits/stdc++.h>
using namespace std;

const int _=1e6+5;

int n,k,rt;
int dep[_];
vector<int>e[_];

void dfs(int u,int fa){
	dep[u]=1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v!=fa){
			dfs(v,u);
			dep[u]=max(dep[u],dep[v]+1);
		}
	}
}
void solve1(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		if(e[u].size()>1)rt=u;
		if(e[v].size()>1)rt=v;
	}
	dfs(rt,0);
	int mx1=0,mx2=0;
	for(int i=0;i<e[rt].size();i++){
		int v=e[rt][i];
		if(dep[v]>mx1){
			mx2=mx1;
			mx1=dep[v];
		}else mx2=max(mx2,dep[v]);
	}
	int ans=1e9;
	for(int i=1;i<=n;i++){
		int x=dep[i]-1;
		if(dep[x]==mx1)x=max(x,mx2+dep[rt]-dep[x]);
		else x=max(x,mx1+dep[rt]-dep[x]);
//		cout<<'!'<<i<<' '<<x<<'\n';
		ans=min(ans,x/2);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--)solve1();
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

1
*/
