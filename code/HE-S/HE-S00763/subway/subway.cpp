#include<bits/stdc++.h>
#define N 410
#define int long long
using namespace std;
const int inf = 1e18;
int c,n,m,d,q;
int w[N],nu[210];
pair<int,int> k[210][N];
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) dis[i][j]=inf;
	}
//	cout<<dis[1][3]<<"**\n";
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>nu[i];
		for(int j=1,u,v;j<=nu[i];j++){
			cin>>u>>v;
			k[i][j]={u,v};
		}
		for(int I=1;I<=nu[i];I++){
			for(int J=I+1;J<=nu[i];J++){
				pair<int,int> u=k[i][I],v=k[i][J];
				dis[u.first][v.first]=min(dis[u.first][v.first],u.second+v.second);
				dis[v.first][u.first]=min(dis[v.first][u.first],u.second+v.second);
			}
		}
	}
	for(int p=1;p<=m;p++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
			
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		cout<<w[u]+w[v]+dis[u][v]<<'\n';
	}
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2 
*/
