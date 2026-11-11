//I AK CSP-S
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=500005,D=25;
int n,m,d,q,dis[N][N],w[M];
int rw[M][D][2];
//railway(id,t)
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,t;
			cin>>u>>t;
			rw[u][++rw[u][0][0]][0]=i;
			rw[u][rw[u][0][0]][1]=t;
		}
	}
	for(int i=1;i<=m;i++){
		if(rw[i][0][0]<=1) continue;
		for(int j=1;j<rw[i][0][0];j++){
			for(int jj=j+1;jj<=rw[i][0][0];jj++){
				dis[rw[i][j][0]][rw[i][jj][0]]=
				dis[rw[i][jj][0]][rw[i][j][0]]=
				rw[i][j][1]+rw[i][jj][1];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v,ans=1e18;
		cin>>u>>v;
		for(int i=1;i<=rw[u][0][0];i++){
			for(int j=1;j<=rw[v][0][0];j++){
				int p=rw[u][i][0],q=rw[v][j][0];
				ans=min(ans,dis[p][q]+w[u]+w[v]+rw[u][i][1]+rw[v][j][1]);
//				cout<<p<<" "<<q<<":"<<dis[p][q]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
