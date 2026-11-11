#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int v[N];
int k[N];//节点p 到所经站台的距离 
ll dis[505][505];//站台i j的距离 
int ff[N][25][2];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) cin>>v[i];
	for(int i=1;i<=n;i++){
		int hh;
		cin>>hh;
		for(int j=1;j<=hh;j++){
			int p,t;
			cin>>p>>t;
			++k[p];
			ff[p][k[p]][0]=i;
			ff[p][k[p]][1]=t;
		}
	}
	for(int i=1;i<=m;i++){
		if(k[i]>=2){
			for(int l=1;l<=k[i];l++){
				for(int r=l+1;r<=k[i];r++){
					int u=ff[i][l][0],v=ff[i][r][0];
					ll w=ff[i][l][1]+ff[i][r][1];
					dis[u][v]=min(w,dis[u][v]);
					dis[v][u]=min(w,dis[v][u]);
				}
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
//	for(int i=1;i<=n;i++) 
	while(q--){
		int x,y;
		ll ans=1e18;
		cin>>x>>y;
		for(int l=1;l<=k[x];l++){
			for(int r=1;r<=k[y];r++){
				ans=min(ans,v[x]+v[y]+ff[x][l][1]+ff[y][r][1]+dis[ff[x][l][0]][ff[y][r][0]]);
			} 
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/ 
