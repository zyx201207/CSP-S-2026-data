#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int c,t,n,k;
int dep[N];
bool edge[N][N];
int fa[N],ancs[N];
vector<int> g[N];
void dfs(int u,int fa){
	ancs[u]=fa;
	dep[u]=dep[fa]+1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		dfs(v,u);
	}
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
int ans=1e9;
int lca(int a,int b){
	while(a!=b){
//		cout<<a<<' '<<b<<'\n';
		if(dep[a]<dep[b])swap(a,b);
		a=ancs[a];
	}
	return a;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		memset(edge,0,sizeof edge);
		ans=1e9;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			edge[u][v]=1;
		}
		dfs(1,0);
		for(int i=0;i<(1<<n);i++){
//			cout<<i<<"\n";
			for(int i=1;i<=n;i++)fa[i]=i;
			vector<int> a;
			for(int j=0;j<=20;j++){
				if((i>>j)&1){
					a.push_back(j+1);
				}
			}
			if(a.size()!=k)continue;
//			cout<<"bbb"<<' '<<a.size()<<"\n";
			for(int i=0;i<a.size();i++){
				for(int j=0;j<a.size();j++){
					int u=a[i],v=a[j];
					if(edge[u][v] and find(u)!=find(v))merge(u,v);
				}
			}
			int cnt=0;
			for(int i=0;i<a.size();i++){
//				cout<<fa[a[i]]<<' ';
				if(fa[i]==i){
					cnt++;
				}
			}
//			puts("");
			if(cnt>2)continue;
			int res=0;
			for(int i=0;i<a.size();i++){
				for(int j=0;j<a.size();j++){
					int u=a[i],v=a[j];
//					cout<<u<<' '<<v<<'\n';
					res=max(res,dep[u]+dep[v]-2*dep[(lca(u,v))]);
				}
			}
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
} 
