#include <bits/stdc++.h>
using namespace std;
int n , d;
int a[200005];
vector<int> G[200005];
int dfn[200005] , low[200005] , timer=0;
int stk[200005] , tot=0;
bool instk[200005];
int scc=0;
void dfs(int u , int fa){
	dfn[u]=low[u]=++timer;
	stk[++tot]=u;
	instk[u]=true;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(dfn[v]==0){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(instk[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		scc++;
		int v=-1;
		while(v!=u){
			v=stk[tot];
			tot--;
			instk[v]=false;
		}
	}
	return ;
}
void solve(){
	cin >>n>>d;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		for(int j=1;j<i;j++){
			if(abs(a[i]-a[j])<=d){
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	} 
	for(int i=1;i<=n;i++){
		if(dfn[i]==0){
			dfs(1,0);
		}
	}
	cout <<scc<<"\n";
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c , t;
	cin >>c>>t;
	while(t--){
		solve();
	} 
	return 0;
} 
