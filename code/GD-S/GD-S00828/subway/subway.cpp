#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lc(i) ((i)<<1)
#define rc(i) ((i)<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
constexpr int M=5e5+5;
constexpr int N=505;
constexpr int D=25;
constexpr int Q=1e5+5;
constexpr ull INF=1e17;
struct edge{
	int v;
	ull w;
};
int caseID;
int n,m,d,q;
ull w[M];
vector<edge>G[M];
ull dis[N][N];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]>=INF)continue;
				if(dis[k][j]>=INF)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>caseID;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x;j<=k;j++){
			ull t;
			cin>>x>>t;
			G[x].push_back((edge){i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(edge &e1:G[i]){
			for(edge &e2:G[i]){
				const int u=e1.v;
				const int v=e2.v;
				if(u==v)continue;
				dis[u][v]=min(dis[u][v],e1.w+e2.w);
				dis[v][u]=min(dis[v][u],e1.w+e2.w);
			}
		}
	}
	floyd();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cerr<<"dis["<<i<<"]["<<j<<"] = "<<dis[i][j]<<'\n';
//		}
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ull d=INF;
		for(edge &ex:G[x]){
			for(edge &ey:G[y]){
				d=min(d,dis[ex.v][ey.v]+ex.w+ey.w);
			}
		}
		cout<<d+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
1~m 地铁站厅
m+1~m+n 地铁线路 

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

对每个地铁站做会爆 
考虑针对线路 
以每一条线路为点跑全源最短路
这是 O(n^3) 的 
对于询问 (x,y)，枚举 x,y 连接的路线点 
这是 O(qd^2) 的
有没有说法？
 
记得开 long long！ 
*/
