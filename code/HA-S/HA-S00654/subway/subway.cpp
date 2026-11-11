#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[405],k[505],s,e,dis[205][205],maxx;
struct sb{
	int stop,time;
}a[2005][5];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			dis[i][j]=0x3fffffff;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j].stop>>a[i][j].time;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=2;l++){
				dis[i][l]=min(dis[i][l],dis[j][l]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		cout<<dis[s][e]<<"\n";
	}
	return 0;
}
