#include<bits/stdc++.h>
using namespace std;
const int M=1e3+7;
long long g[M][M];
int a[M],b[M],w[M];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		for(int j=1;j<=m;j++)g[i][j]=1e18;
		g[i][i]=0;
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[j]>>b[j];
		for(int j=1;j<=k;j++){
			for(int o=1;o<=k;o++){
				if(j==o)continue;
				g[a[j]][a[o]]=b[j]+b[o];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			for(int o=1;o<=m;o++){
				if(i==o||j==o)continue;
				if(g[i][o]==1e18||g[o][j]==1e18)continue;
				g[i][j]=min(g[i][j],g[i][o]+g[o][j]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<i<<" "<<j<<":"<<g[i][j]<<"\n";
//		}
//	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		cout<<g[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
