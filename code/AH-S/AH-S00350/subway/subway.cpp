#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
#define ll long long
int c,n,m,d,q,i,j,k,u,v,x,y,l;
ll w[M],f[N][N],t,mi;
vector<pair<int,ll>> g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>u>>t;
			g[u].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof f);
	for(u=1;u<=m;u++){
		l=g[u].size();
		for(i=0;i<l-1;i++){
			for(j=i+1;j<l;j++){
				x=g[u][i].first;y=g[u][j].first;
				f[y][x]=f[x][y]=min(f[x][y],g[u][i].second+g[u][j].second);
			}
		}
	}
	for(i=1;i<=n;i++)f[i][i]=0;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
			}
		}
	}
	while(q--){
		cin>>u>>v;
		mi=1e17;
		for(auto a:g[u]){
			for(auto b:g[v]){
				mi=min(mi,f[a.first][b.first]+a.second+b.second);
			}
		}
		cout<<mi+w[u]+w[v]<<"\n";
	}
}
