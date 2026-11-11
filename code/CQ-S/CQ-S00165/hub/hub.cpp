#include<bits/stdc++.h>
using namespace std;
//#define int long long
//luogu id afewdgre
int c,t,n,k,flag[35],fa[35],dep[35];
vector<int> g[500005];
void dfs(int u){
	for(auto x:g[u]){
		if(flag[x]==1){
			flag[x]=0;
			dfs(x);
		} 
	} 
}
void ta(int u,int v){
	fa[u]=v,dep[u]=dep[v]+1;
	for(auto x:g[u]){
		if(x!=v) ta(x,u);
	}
}
int lca(int x,int y){
	int num=0;
	if(x==y) return 0;
	if(dep[x]>dep[y]) swap(x,y);
	while(dep[x]<dep[y]) y=fa[y],num++;
	if(x==y) return num;
	while(x!=y) x=fa[x],y=fa[y],num+=2;
	return num+2;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int minn=1e9;
		ta(1,0);
		for(int i=1;i<=(1<<n);i++){
			int num=0,id=0,x[35]={};
			for(int j=0;j<=n;j++){
				if(i&(1<<j))flag[j]=1,id++,x[j]=1;
			}
			if(id>k) continue;
			for(int j=1;j<=n;j++){
				if(flag[j]){
					num++;
					dfs(j);
				} 
			}
			if(num<=2){
				int maxn=0;
				for(int i=1;i<=n;i++){
					int minn1=1e9;
					for(int j=1;j<=n;j++){
						if(x[j]){
							minn1=min(minn1,lca(i,j));
						} 
					}
					maxn=max(maxn,minn1);
				}
				
				minn=min(minn,maxn);
			}
		}
		cout<<minn<<'\n';
	}
}

