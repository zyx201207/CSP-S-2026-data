#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,C,m,d[6002][6002],q,dd,w[6002];
void add(int u,int v,int w){
	d[u][v]=min(d[u][v],w);
	d[v][u]=min(d[v][v],w);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);  

	cin>>C>>n>>m>>dd>>q;
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			d[i][j]=1000000000000000018;
		}
	}
	for(int i=1;i<=m;i++){cin>>w[i];}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int ii=1;ii<=k;ii++){
			int a,t;cin>>a>>t;
			add(m+i,a,t);
		}
	}
	for(int k=1;k<=m+n;k++)
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){d[i][j]=min(d[i][j],d[i][k]+d[k][j]);}}
	while(q--){
		int u,v;cin>>u>>v;
		cout<<w[u]+w[v]+d[u][v]<<"\n";
	}
}
