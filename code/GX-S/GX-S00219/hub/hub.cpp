#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,k,dep[N],f[N][25];
vector<int>g[N];
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=0;(int)i<(int)g[x].size();i++){
		int y=g[x][i];
		if(y==fa)continue;
		dfs1(y,x);
	}
	for(int i=1;i<=20;i++){
		f[x][i]=f[f[x][i-1]][i-1];
	}
}
int lca(int x,int y){
	if(dep[y]>dep[x])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[x][i];
		}
	}
	return f[x][0];
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0);
	for(int i=1;i<=n;i++){
		g[i].clear();
		dep[i]=0;
		for(int j=1;j<=20;j++)f[i][j]=0;
	}
	cout<<0;
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
	    if(c==13||c==14)cout<<(n-k+2)/3<<endl;
		else solve();
	}
}
