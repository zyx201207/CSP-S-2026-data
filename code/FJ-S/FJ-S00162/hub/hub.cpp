#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
int n,k;
vector<int> g[N];
ll dep[N],de[N][30];
void dfs(int u,int pa){
	dep[u]=dep[pa]+1;
	de[u][0]=pa;
	for(int v:g[u]){
		if(v==pa) continue;
		dfs(v,u);
	}
}
void qde(){
	for(int i=1;i<30;i++){
		for(int j=1;j<=n;j++){
			de[j][i]=de[de[j][i-1]][i-1];
		}
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=29;i>=0;i--) if(dep[de[u][i]]>=dep[v]) u=de[u][i];
	if(u==v) return u;
	for(int i=29;i>=0;i--) if(de[u][i]!=de[v][i]) u=de[u][i],v=de[v][i];
	return de[u][0];
}
int qdis(int u,int v){
	int l=lca(u,v);
	return dep[u]+dep[v]-2*dep[l];
}
void solve(){
	cin >> n >>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	qde();
	int mn=INT_MAX;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int mx=0;
			for(int k=1;k<=n;k++){
				mx=max(mx,min(qdis(i,k),qdis(j,k)));
			}
			mn=min(mn,mx);
		}
	}
	cout <<mn << '\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >>c >>t;
	while(t--){
		solve();
	}
	return 0;
}
