#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,inf=1e18;
int n,m,q,w[M],f[N][N];
basic_string< array<int,2> > g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,y;j<=k;j++)cin>>x>>y,g[x]+={i,y};
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=inf;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)for(auto j:g[i])for(auto k:g[i])if(j[0]!=k[0])f[j[0]][k[0]]=f[j[0]][k[0]]=min(f[j[0]][k[0]],j[1]+k[1]);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int u,v,ans=inf;cin>>u>>v;
		for(auto i:g[u])for(auto j:g[v])ans=min(ans,i[1]+f[i[0]][j[0]]+j[1]);
		cout<<w[u]+ans+w[v]<<'\n';
	}
}
