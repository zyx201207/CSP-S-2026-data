#include<bits/stdc++.h>
using namespace std;
const int N=2000;
struct dian{
	int id,time;
};
int c,n,m,d,q,k[N],cnt;
long long w[N],dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			dis[x][m+i]=y;
			dis[m+i][x]=y;
		}
	}
	for(int i=1;i<=n+m;i++)dis[i][i]=0;
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			for(int u=1;u<=n+m;u++){
				if(dis[i][j]>dis[i][u]+dis[u][j]){
					dis[i][j]=dis[i][u]+dis[u][j];
					dis[j][i]=dis[i][u]+dis[u][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		cout<<w[l]+w[r]+dis[l][r]<<'\n';
	}
	return 0;
}
