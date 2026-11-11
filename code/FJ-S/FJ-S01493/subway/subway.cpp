#include<bits/stdc++.h>
using namespace std;

const int N=510,M=5e5+10,D=30;
int c,n,m,d,q,k,a,x,y,u,v,t[N][M],g[M][D],w[M],cnt[M];
long long dis[N][N],ans;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(t,0x3f,sizeof(t));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		cin>>k;
		while(k--){
			cin>>a;
			cin>>t[i][a];
			g[a][++cnt[a]]=i;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=cnt[k];i++){
			u=g[k][i];
			for(int j=i+1;j<=cnt[k];j++){
				v=g[k][j];
				dis[u][v]=min(dis[u][v],(long long)t[u][k]+t[v][k]);
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ans=LLONG_MAX;
		cin>>x>>y;
		for(int i=1;i<=cnt[x];i++){
			u=g[x][i];
			for(int j=1;j<=cnt[y];j++){
				v=g[y][j];
				ans=min(ans,dis[u][v]+t[u][x]+t[v][y]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
