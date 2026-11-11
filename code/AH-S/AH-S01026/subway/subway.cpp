#include "bits/stdc++.h"
using namespace std;
/*
乘坐线路不需要时间喵
只需要关心：
线路数量 <=500
进入的线路 A
出去的线路 B
d^2<=400 枚举即可
剩下的直接考虑每两个互达，直接枚举地铁站的 O(md^2) 建立 g[i][j]
时间 O(md^2+qd^2+n^3)
空间 O(md+n^2)

O(md^2) 有点紧
考虑 O(mlogm+md)
则排序后枚举两个线路 (n^2)，双指针扫一遍。
时间 O(nm)
闹麻了更大了，写个蛋
*/
typedef long long ll1;
#define pii pair<int,int>
#define mkp make_pair
#define fir first
#define sec second
const int N=505,M=5e5+5;
const ll1 inf=1e16+5;
int n,m,q;
ll1 w[M];vector<pii>eg[M];
ll1 g[N][N];
void work(){
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			g[i][j]=inf;
		g[i][i]=0;
	}
	for(int i=1,cnt,u,t;i<=n;i++){
		scanf("%d",&cnt);
		while(cnt--){
			scanf("%d%d",&u,&t);
			eg[u].emplace_back(mkp(i,t));
		}
	}
	for(int u,v,k=1;k<=m;k++)
	for(int i=0;i<eg[k].size();i++)
	for(int j=i;j<eg[k].size();j++){
		u=eg[k][i].fir,v=eg[k][j].fir;
		g[u][v]=g[v][u]=min(g[u][v],1ll*eg[k][i].sec+1ll*eg[k][j].sec);

	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cerr<<g[i][j]<<" ";
		}
		cerr<<"\n";
	}
	*/
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	}
	//floyd
	//for(int i=1;i<=n;i++)
	//for(int j=1;j<=n;j++)
	//	assert(g[i][j]<inf);
	ll1 Ans=0;
	int X,Y;
	while(q--){
		scanf("%d%d",&X,&Y);
		Ans=inf;
		for(auto [x,tx]:eg[X])
		for(auto [y,ty]:eg[Y]){
			Ans=min(Ans,1ll*w[X]+1ll*w[Y]+1ll*tx+1ll*ty+g[x][y]);
		}
		printf("%lld\n",Ans);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int Tid,EDG;
	scanf("%d%d%d%d%d",&Tid,&n,&m,&EDG,&q);
	work();
	return 0;
}