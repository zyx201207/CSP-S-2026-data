#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
struct edge{
	int to,val,bh;
};
struct car{
	int k,f[21];
}cr[N];

int c,n,m,d,q,w[M],t1[M][N];
vector<edge> e[N];
int ans(int s,int t){
	int dis[N]={};
	bool vis[N]={};
	for(int i=0;i<=n;i++){dis[i]=INT_MAX;}
	dis[s]=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(!vis[j] && dis[u]>dis[j]){u=j;}
		}
		vis[u]=1;
		for(edge nx:e[u]){
			int v=nx.to,w=nx.val,j=nx.bh;
			if(dis[v]>dis[u]+t1[u][j]+w){dis[v]=dis[u]+w+t1[u][j];}
		}
	}
	return w[s]+dis[t]+w[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){cin>>w[i];}
	for(int i=1;i<=n;i++){
		cin>>cr[i].k;
		for(int j=1;j<=cr[i].k;j++){
			cin>>cr[i].f[j]>>t1[cr[i].f[j]][i];
		}
		if(cr[i].k==2){
			int u=cr[i].f[1],v=cr[i].f[2];
			e[u].push_back({v,t1[cr[i].f[2]][i],i});
			e[v].push_back({u,t1[cr[i].f[1]][i],i});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<ans(x,y)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
