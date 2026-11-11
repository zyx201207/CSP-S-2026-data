#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int c,t,n,k,dep[N],len[N],fa[N][24];
vector<int> g[N];

void dfs(int u,int f){
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=1;i<=21;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==f){
			continue;
		}
		dfs(v,u);
		len[u]=max(len[u],len[v]+1);
	}
}

int lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=21;i>=0;i--){
		if(dep[fa[u][i]]>=dep[v]){
			u=fa[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=21;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(len,0,sizeof(len));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
//		dfs(1,1);
		if(k==n){
			cout<<0<<'\n';
		}
		else{
			cout<<(n/2+1-k+2+2)/3<<'\n';
		}
/*		for(int i=1;i<=n;i++){
			g[i].clear();
		}*/
	}
	return 0;
}
