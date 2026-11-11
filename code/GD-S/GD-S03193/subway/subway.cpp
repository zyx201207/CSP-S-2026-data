#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;//地铁站总数 
const int N=505;//线路总数 
int c,n,m,d,q;
int w[M];
int dist[N][N];
int t[N][M];
int ztx[M][25],k[M];//第i个站点的第j个线路 
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int z=1;z<=n;z++){
				dist[j][z]=min(dist[j][i]+dist[i][z],dist[j][z]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=600;i++){
		for(int j=1;j<=600;j++){
			if(i==j) continue;
			dist[i][j]=1e9+10;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int tk;
		cin>>tk;
		for(int j=1;j<=tk;j++){
			int id,val;//地铁站编号，用时 
			cin>>id>>val;
			t[i][id]=val;//第i条线路到地铁站id的站厅的走路时间 
			ztx[id][++k[id]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<k[i];j++){
			for(int z=j+1;z<=k[i];z++){
				int edx=ztx[i][j],edy=ztx[i][z];
				if(dist[edx][edy]==1e9+10){
					dist[edx][edy]=dist[edy][edx]=t[edx][i]+t[edy][i];
					continue;
				}
				dist[edx][edy]=max(dist[edx][edy],t[edx][i]+t[edy][i]);
				dist[edy][edx]=dist[edx][edy];
			}
		}
	}
	floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e9+10;
		for(int i=1;i<=k[x];i++){
			for(int j=1;j<=k[y];j++){
				int edx=ztx[x][i],edy=ztx[y][j];
				ans=min(ans,dist[edx][edy]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
