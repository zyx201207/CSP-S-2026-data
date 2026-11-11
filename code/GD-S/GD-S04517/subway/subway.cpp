#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int ti[500005][22];
int roa[500005][22];
int dis[510][510];
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1,k; i<=n; i++) {
		cin>>k;
		for(int sta,tt,j=1; j<=k; j++) {
			cin>>sta>>tt;
			roa[sta][++roa[sta][0]]=i;
			ti[sta][++ti[sta][0]]=tt;
			//sta站的第 ++roa[sta][0]条线为i，到站台的时间为tt
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int sta=1; sta<=m; sta++) {
		for(int i=1; i<=roa[sta][0]; i++) {
			for(int j=i+1; j<=roa[sta][0]; j++) {
				dis[roa[sta][i]][roa[sta][j]]=ti[sta][i]+ti[sta][j];
				dis[roa[sta][j]][roa[sta][i]]=ti[sta][i]+ti[sta][j];
				//sta号站第i号线到第j号线的时间
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int sta=1;sta<=m;sta++){
//		for(int i=1;i<=roa[sta][0];i++){
//			for(int j=i+1;j<=roa[sta][0];j++){
//				r[roa[sta][i]].push_back({roa[sta][j],ti[sta][i]+ti[sta][j]});
//				r[roa[sta][j]].push_back({roa[sta][i],ti[sta][i]+ti[sta][j]});
//				//sta号站第i号线到第j号线的时间
//			}
//		}
//	}
	int x,y,u,v;
	while(q--) {
		cin>>x>>y;
		if(x==y){
			cout<<"0"<<endl;
			continue;
		}
		int ans=10000000000000000;
		for(int i=1;i<=roa[x][0];i++){
			for(int j=1;j<=roa[y][0];j++){
				u=roa[x][i];
				v=roa[y][j];
				ans=min(ans,dis[u][v]+ti[x][i]+ti[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
}
