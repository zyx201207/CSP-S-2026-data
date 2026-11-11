#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
long long dis[505][505];
struct pt{
	int a;long long d;
};
vector<pt>ve[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			pt tmp;
			cin>>tmp.a>>tmp.d;
			ve[tmp.a].push_back({i,tmp.d});
		}
	}for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=1000000000000000ll;
	for(int i=1;i<=m;i++){
		int k=ve[i].size();
		for(int j=0;j<k;j++){
			for(int l=j+1;l<k;l++){
				int u=ve[i][j].a,v=ve[i][l].a;
				dis[u][v]=min(dis[u][v],ve[i][j].d+ve[i][l].d);
				dis[v][u]=min(dis[v][u],ve[i][j].d+ve[i][l].d);
			}
		}
	}for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int len=ve[x].size(),jen=ve[y].size();
		long long ans=1000000000000000000ll;
		for(int j=0;j<len;j++){
			for(int k=0;k<jen;k++){
				int a=ve[x][j].a,b=ve[y][k].a;
				ans=min(ans,w[x]+w[y]+dis[a][b]+ve[x][j].d+ve[y][k].d); 
			//	cout<<a<<' '<<b<<' '<<w[x]+w[y]+dis[a][b]+ve[x][j].d+ve[y][k].d<<'\n'; 
			}
		}cout<<ans<<endl;
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
