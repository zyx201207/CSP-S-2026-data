#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int N=510,M=5e3+10;
struct disnode{
	int firstline,dis,lastline;
} dis[M][M];
int lines_stn[N][M];
int w[N];
int stn_line_nums[M],stn_lines[M][N],stn_to_line[M][N];
int k[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j].dis=inf;
			dis[i][j].lastline=inf;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,t;
			cin>>x>>t;
			stn_to_line[x][i]=t;
			lines_stn[i][j]=x;
			stn_lines[x][++stn_line_nums[x]]=i;
		}
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				dis[lines_stn[i][j]][lines_stn[i][l]]={i,0,i};
			}
		}
	}
	for(int p=1;p<=m;p++){
		if(stn_line_nums[p]<2)continue;
		for(int x=1;x<=m;x++){
			for(int y=1;y<=m;y++){
				if(dis[x][y].dis==0)continue;
				if(dis[x][p].lastline!=inf&&dis[p][y].firstline!=inf){
					int flag=0;
					for(int i=1;i<=stn_line_nums[p];i++){
						if(dis[x][p].lastline==stn_lines[p][i])flag++;
						if(dis[p][y].firstline==stn_lines[p][i])flag++;
					}
					if(flag>=2){
						int firstline=dis[x][p].firstline,lastline=dis[p][y].lastline;
						int chfirstline=dis[p][y].firstline,chlastline=dis[x][p].lastline;
						int dist=dis[x][p].dis+dis[p][y].dis+stn_to_line[p][chfirstline]+stn_to_line[p][chlastline];
						if(dist<dis[x][y].dis){
							dis[x][y]={firstline,dist,lastline};
						}
					}
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		disnode d=dis[x][y];
		cout<<w[x]+stn_to_line[x][d.firstline]+d.dis+stn_to_line[y][d.lastline]+w[y]<<'\n';
	}
	return 0;
}
