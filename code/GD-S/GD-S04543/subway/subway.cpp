#include<bits/stdc++.h>
#define ll long long
#define Furinas return
#define Tears 0
#define Arias 1
#define N 500005
#define M 505
using namespace std;
ll c,n,m,d,q,w[N],k[M],dis[M][M];
struct node{
	ll id,val;
};
vector <node> v[N],g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(Tears);
	cin.tie(Tears);cout.tie(Tears);
	cin>>c>>n>>m>>d>>q;
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll qa,qt;
			cin>>qa>>qt;
			v[qa].push_back({i,qt});
			g[i].push_back({qa,qt});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(node y:v[g[i][j].id]){
				if(y.id==i) continue;
				dis[i][y.id]=min(dis[i][y.id],y.val+g[i][j].val);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int k=1;k<=n;k++){
				if(k==i||k==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll qx,qy;
		cin>>qx>>qy;
		ll ans=1e18+7;
		for(auto y:v[qx]) for(auto p:v[qy]) ans=min(ans,dis[y.id][p.id]+y.val+p.val);
		cout<<ans+w[qx]+w[qy]<<'\n';
	}
	Furinas Tears;
}
/*
首先wi没什么用 就开始的时候进去和结束的时候出来而已
很显然 后面要O(log)得出答案 所以前面要预处理
没有地铁内运行的时间 只有总步行的时间
因为只有500条线路 所以很显然 最多换乘499次
先对于每一条线路 当成一个连通块 对于一条线路内 任意两点距离为0
考虑预处理dp i j 代表从第i条线路走到第j条线路的最少步行时间
一个点最多换乘20个
所以对于每条线路的每个点都可以先存下来可以换乘到哪个线 时间用时为多少
然后对于每一条线 所有都要取min值
然后我们得到了一个只有500个点的图 然后跑一遍多源最短路即可
轻轻松松
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
