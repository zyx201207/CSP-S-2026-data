#include<bits/stdc++.h>
using namespace std;
int w[500005];
vector<pair<int,int> >vt[500005];
long long dis[505][505];
int c,d,m,n,q;
void floyd(){
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
//	cout<<"E!\n";
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			vt[a].push_back(make_pair(i,t));
			int l=vt[a].size()-1;
			for(int j=0;j<vt[a].size();j++){
			//	if(vt[a][j].second<0){
			//		cout<<j<<" "<<vt[a][j].second<<"\n";
			//	}
				long long T=min(dis[i][vt[a][j].first],1ll*vt[a][j].second+t);
				dis[i][vt[a][j].first]=dis[vt[a][j].first][i]=T;
			}
		}
	}
//	cout<<"E!\n";
	floyd();
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=LLONG_MAX;
		int lx=vt[x].size(),ly=vt[y].size();
		for(int i=0;i<lx;i++){
			for(int j=0;j<ly;j++){
				ans=min(ans,dis[vt[x][i].first][vt[y][j].first]+w[x]+w[y]+vt[x][i].second+vt[y][j].second);
			}
		}
	//	if(ans<0){
//			for(int i=0;i<lx;i++){
//				for(int j=0;j<ly;j++){
//					if(ans==dis[vt[x][i].first][vt[y][j].first]+w[x]+w[y]+vt[x][i].second+vt[y][j].second){
//						cout<<w[x]<<" "<<vt[x][i].second<<" "<<dis[vt[x][i].first][vt[y][j].first]<<" "<<vt[y][j].second<<" "<<w[y]<<"\n";
//					}
//				}
//			}
//			
	//	}
		printf("%lld\n",ans);
	}
	return 0;
}
