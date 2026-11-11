#include<iostream>
#include<vector>
using namespace std;
int c,n,m,d,q;
int w[(int)5e5+5];
struct line{
	int id,t;
};
vector<line> bin[(int)5e5+5];
long long dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		int a,t;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			bin[a].push_back(line{i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int x=0;x<bin[i].size();x++){
			for(int y=x+1;y<bin[i].size();y++){
				dis[bin[i][x].id][bin[i][y].id]=min(dis[bin[i][x].id][bin[i][y].id],1ll*bin[i][x].t+bin[i][y].t);
				dis[bin[i][y].id][bin[i][x].id]=min(dis[bin[i][y].id][bin[i][x].id],1ll*bin[i][x].t+bin[i][y].t);
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
	int x,y;
	while(q--){
		cin>>x>>y;
		long long ans=1e18;
		for(int i=0;i<bin[x].size();i++){
			for(int j=0;j<bin[y].size();j++){
				ans=min(ans,dis[bin[x][i].id][bin[y][j].id]+bin[x][i].t+bin[y][j].t);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}

