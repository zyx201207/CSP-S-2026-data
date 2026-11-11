#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,qq;
int w[500005];
int f[505][505];
struct sub{
	int x,y;
};
int ct[505];
vector<sub>p[500005];
int dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ct[i];
		for(int j=1;j<=ct[i];j++){
			int x,y;
			cin>>x>>y;
			p[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<p[i].size();j++){
			for(int k=j+1;k<p[i].size();k++){
				f[p[i][j].x][p[i][k].x]=min(f[p[i][j].x][p[i][k].x],p[i][j].y+p[i][k].y);
				f[p[i][k].x][p[i][j].x]=min(f[p[i][k].x][p[i][j].x],p[i][j].y+p[i][k].y);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=f[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(qq--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=0;i<p[x].size();i++){
			for(int j=0;j<p[y].size();j++){
				int p1=p[x][i].x,p2=p[y][j].x;
				int d1=p[x][i].y,d2=p[y][j].y;
				ans=min(ans,w[x]+w[y]+dis[p1][p2]+d1+d2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
