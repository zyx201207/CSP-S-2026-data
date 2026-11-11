#include <iostream>
#include <utility>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;
const int N=20;
int n,k;
int dep[N],fa[N];
bool a[N];
bool vs[N];
vector<int>G[N];
void dfs(int u){
	if(vs[u]||(a[u]==0)) return;
	vs[u]=1;
	for(int v:G[u]) dfs(v);
}
void pdfs(int u,int ff){
//	cout<<u<<' ';
	dep[u]=dep[ff]+1;
	fa[u]=ff;
	for(int v:G[u])if(v!=ff){
		pdfs(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int delta=dep[u]-dep[v];
	for(int j=0;j<delta;j++)  u=fa[u];
	if(u==v)return u;
	while(u!=v){
		u=fa[u];v=fa[v];
	}
	return u;
}
int gdis(int u,int v){
	int x=lca(u,v);
	return dep[u]+dep[v]-2*dep[x];
}
bool check(){
	int cnt=0;
	memset(vs,0,sizeof(vs));
	for(int i=1;i<=n;i++)if(a[i]){
		if(vs[i]==0){
			++cnt;
			dfs(i);
			if(cnt>2)return 0;
		}
	}
	return 1;
}

int gf(){
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]&&a[j]) res=max(res,gdis(i,j));
		}
	}
	return res;
}
int Ctest,test;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>Ctest>>test;
	while(test--){
		cin>>n>>k;
		int ans=n;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		pdfs(1,0);
		//cout<<gdis(2,3)<<"\n\n";
		for(int s=0;s<(1<<n);s++){
			int num=0;
			for(int j=0;j<n;j++){
				if((1<<j)&s) ++num;
			}
			if(num!=k) continue;
			for(int j=0;j<n;j++){
				if((1<<j)&s) a[j+1]=1;
				else a[j+1]=0;
			}
			if(check()) ans=min(ans,gf());
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) G[i].clear();
	//	if(test==1) return 0;
	}

	return 0;
}


