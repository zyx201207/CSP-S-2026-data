#include<bits/stdc++.h>
using namespace std;
int dis[1005][1005],w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=INT_MAX/2;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,a,t,pr=0,sj=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			dis[pr][a]=min(dis[pr][a],t+sj);
			pr=a;sj=t;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		cout<<dis[u][v]+w[u]+w[v]<<endl;
	}
	return 0;
}
