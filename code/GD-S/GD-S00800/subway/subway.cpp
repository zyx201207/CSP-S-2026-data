#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long ans;
int k[510],w[500010];
long long t[510][500010];
struct node{
	int v;
	int id;
};
vector<node> g[500010];
void dfs(int u,int x,long long times,int road){
	if(u==x){
		ans=min(times,ans);
		return;
	}
	for(auto i:g[u]){
		if(road!=i.id){
			dfs(i.v,x,times+t[road][u]+t[i.id][u],i.id);
		}
		else{
			dfs(i.v,x,times,road);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){ 
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int u=0;
		for(int j=1;j<=k[i];j++){
			int a;
			cin>>a>>t[i][j];
			g[u].push_back({a,i});
			u=a;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=0;
		dfs(x,y,w[x]+w[y],0);
		cout<<ans<<'\n';
	}
	return 0;
}
