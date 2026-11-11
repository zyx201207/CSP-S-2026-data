#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=505,M=5e5+5,INF=1e18;
int w[M];
vector<array<int,2>> b[M];
ll d[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway7.in","r",stdin);
//	freopen("out.out","w",stdout);
//	int bg=clock();
	ios::sync_with_stdio(0),cin.tie(0);
	int c,n,m,D,q;cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int ln,i=1;i<=n;i++){
		cin>>ln;
		for(int x,t;ln--;)
			cin>>x>>t,b[x].push_back({i,t});
	}
	for(int i=1;i<=n;i++) fill_n(d[i]+1,n,INF),d[i][i]=0;
	for(int i=1;i<=m;i++)
		for(size_t x=0;x<b[i].size();x++)
			for(size_t y=x+1;y<b[i].size();y++){
				int u=b[i][x][0],v=b[i][y][0];
				d[u][v]=d[v][u]=b[i][x][1]+b[i][y][1];
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++) if(d[i][k]!=INF)
			for(int j=1;j<=n;j++) if(d[k][j]!=INF)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int x,y;q--;){
		cin>>x>>y;ll ans=INF;
		for(size_t i=0;i<b[x].size();i++)
			for(size_t j=0;j<b[y].size();j++){
				int u=b[x][i][0],v=b[y][j][0];
				if(d[u][v]!=INF) ans=min(ans,d[u][v]+b[x][i][1]+b[y][j][1]);
			}
		cout<<ans+w[x]+w[y]<<"\n";
	}
//	cerr<<"Time: "<<(clock()-bg);
}
