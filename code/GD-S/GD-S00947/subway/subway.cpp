#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=2<<60;
ll c,n,m,d,q,w[20002],k,t[502][20002],b[20002][502];
ll g[502][502],dis[502][502],x,y,a[502][20002],tt;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("t.txt","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		g[i][j]=INF;dis[i][j]=INF;
	}
	for(int i=1;i<=n;i++){//n roads
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];cin>>t[i][a[i][j]];//road i to step aij
			b[a[i][j]][i]=t[i][a[i][j]];//step aij to road i
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)cout<<t[i][j]<<' ';
//		cout<<'\n';
//	}//////
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(b[i][j]&&b[i][l]){//?????
					g[j][l]=min(g[i][l],t[i][j]+t[i][l]);
					g[l][j]=g[j][l];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(g[i][l]<INF&&g[j][l]<INF){
					dis[i][j]=min(dis[i][j],g[i][l]+g[j][l]);
					dis[j][i]=dis[i][j];
				}
			}
		}
	}
	//for(int j=1;j<=n;j++)for(int l=1;l<=n;l++)cout<<g[j][l]<<' ';
	while(q--){
		cin>>x>>y;
		ll ans=w[x]+w[y];ll mnn=INF;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(b[x][i]&&b[y][j])mnn=min(mnn,g[i][j]);
				
			}
			
		}ans+=mnn;cout<<ans<<'\n';
	}
	
	return 0;
} 
