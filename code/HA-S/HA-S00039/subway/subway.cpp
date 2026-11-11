#include <bits/stdc++.h>
using namespace std;
#define int long long
int dis[5010][5010];
int a[500010];
const int INF=1e9;

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=INF;
		}
	}
	int nn=m+1;	
	for(int i=1;i<=5000;i++){
		for(int j=1;j<=5000;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			dis[nn][v]=min(dis[nn][v],w);
			dis[v][nn]=min(dis[v][nn],w);
			
		}
		nn++;
	}	




	for(int k=1;k<=nn;k++){
		for(int i=1;i<=nn;i++){
			for(int j=1;j<=nn;j++){
				if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		cout<<dis[u][v]+a[u]+a[v]<<endl;
	}
	return 0;
}