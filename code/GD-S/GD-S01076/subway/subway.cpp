#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll
using VI=vector<int>;
using PI=pair<int,int>;
const int N=505,M=5e5+5;
const ll inf=2e18;
int c,n,m,d,q,id[N];VI way[M];
int w[M],t[N][M];ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];//地铁口到站厅的时间 
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		int num;cin>>num;
		for(int j=1;j<=num;j++){
			ll x,nt;cin>>x>>nt;//站厅到站台的时间 
			t[i][x]=nt;way[x].push_back(i);
			dis[i][i]=0;
		}
	}
	for(int x=1;x<=m;x++){
		for(int i=0;i<(int)way[x].size();i++){
			for(int j=i+1;j<(int)way[x].size();j++){
				int u=way[x][i],v=way[x][j];
				ll sum=t[u][x]+t[v][x];
				dis[u][v]=min(dis[u][v],sum);
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	for(int I=1;I<=q;I++){
		int x,y;cin>>x>>y;ll ans=inf;
		for(int i=0;i<(int)way[x].size();i++){
			for(int j=0;j<(int)way[y].size();j++){
				int u=way[x][i],v=way[y][j];
				if(u==v)ans=min(ans,(ll)((ll)w[x]+(ll)t[u][x]+(ll)t[v][y]+(ll)w[y]));
				else ans=min(ans,dis[u][v]+(ll)((ll)w[x]+(ll)t[u][x]+(ll)t[v][y]+(ll)w[y]));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
因为 m 非常大不论如何都对求答案都很麻烦，考虑把对于每个站台之间压成路线的关系 
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
