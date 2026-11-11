#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+7,N=507;
struct edge{
	int id,t;//换乘的时间t,id为在哪里换乘
};
int c,n,m,d,q;
int w[M],k[N],dis[N][N];
vector<edge> G[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			edge h;
			cin>>h.id>>h.t;
			G[h.id].push_back({i,h.t});//这个点可以去第i条线了，到站厅为t
		}
	}
	for(int i=1;i<=m;i++) {//枚举每一个点
		for(int j=0;j<G[i].size();j++) {
			auto u=G[i][j];//第一条线
			for(int l=0;l<G[i].size();l++) {
				auto v=G[i][l];//第二条线
				if(l==j) continue;
				dis[v.id][u.id]=dis[u.id][v.id]=min(dis[u.id][v.id],u.t+v.t);
			}
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--) {
		int x,y;
		int ans=100000000000000;
		cin>>x>>y;
		for(int j=0;j<G[x].size();j++) {//第一个点能去的所有线路
			auto u=G[x][j];//第一条线
			for(int l=0;l<G[y].size();l++) {//第二个点能去的所有线路
				auto v=G[y][l];//第二条线
				if(u.id==v.id) {
					ans=min(ans,u.t+v.t);
				}
				else ans=min(ans,dis[u.id][v.id]+u.t+v.t);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
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
