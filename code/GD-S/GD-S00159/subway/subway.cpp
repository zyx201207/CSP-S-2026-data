#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int res=0;
	char c='0';
	while(c>='0'&&c<='9'){
		res=res*10+(int)(c-'0');
		c=getchar();
	}
	return res;
} 

const int M=5e5+5,N=505,inf=0x3f3f3f3f3f3f;
int c,n,m,d,q,w[M],fld[N][N];
struct edge{ int v,w; };
vector<edge>gfx[M];
//gfx[i][j]代表第 i 个地铁站连接到的第 j 条线路的编号与时间（广佛线缩写） 
void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(fld[i][k]==inf||fld[k][j]==inf) continue;
				fld[i][j]=min(fld[i][j],fld[i][k]+fld[k][j]);
			}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read(),n=read(),m=read(),d=read(),q=read(); 
	for(int i=1;i<=m;i++) w[i]=read();
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			fld[i][j]=inf;
	for(int i=1;i<=n;i++) fld[i][i]=0;
	
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		for(int j=1;j<=k;j++){
			int a,wei;
			a=read(),wei=read();
			gfx[a].push_back({i,wei});
		}
	}
	
	for(int i=1;i<=m;i++){
		int len=gfx[i].size();
		if(gfx[i].size()<=1) continue;
		for(int j=0;j<len;j++)
			for(int o=0;o<len;o++)
				if(j!=o){
					int sw1=gfx[i][j].v,we1=gfx[i][j].w;
					int sw2=gfx[i][o].v,we2=gfx[i][o].w;
					fld[sw1][sw2]=min(fld[sw1][sw2],we1+we2);
					fld[sw2][sw1]=min(fld[sw2][sw1],we1+we2);
				}
	}//初始化一下每条线路之间边的时间
	 
	floyd();//处理一下每个线路之间的最短路 
	
	while(q--){
		int x,y,ans=0,minn=inf;
		x=read(),y=read();
		int lenx=gfx[x].size(),leny=gfx[y].size();
		for(int i=0;i<lenx;i++)
			for(int j=0;j<leny;j++){
				int swx=gfx[x][i].v,wex=gfx[x][i].w;
				int swy=gfx[y][j].v,wey=gfx[y][j].w;
				minn=min(minn,fld[swx][swy]+wex+wey);
			}//看他走哪个线路最优 
		ans+=minn;
		ans+=w[x]+w[y];
		printf("%lld\n",ans); 
	} 
	return 0;
}
/*
史山超长题面（
样例
0 2 5 20 2 ==> c,n,m,d,q
c：测试点，判特殊性质
n：线路数量
m：地铁站数量
d：啥玩意？
q：出行计划数，也就是访问数量 
4 1 9 2 5
从地铁站到站厅的时间 
3 1 5 2 7 4 6
第一个 3：经过几个站
后面两两一组，一个是地铁站，另一个是站台到站厅的时间 
3 2 3 3 4 5 7 同理 
1 3 询问了 
1 2
读题比切 T1 还久（
所以说一个地铁站可以分为：
地铁口   站台   站厅
所以说是一道图论最短路 + 大模拟
d 到底是啥（  

3:24 p.m. 注意到 d 有滚木作用
只算步行时间，也就是说线路间的边权为 0
但好像也不是缩点（绝对不是因为我不熟 Tarjan）
其实可以直接建个图 然后暴力 floyd 
等一下，发现 d 的作用好像超过了滚木
一个站可以连 d 条线路，一条线路里两个站可以瞬间到达
注意到 n,d 都很小 可以把一个线路看作一个点（吗？）

在这道题里面一个地铁站拆成了三个点
注意到地铁口仅在起点和终点有用，忽略不计 
那就剩下站台和站厅两个点
而在同一线路内的不同站台可以瞬间到达……呃呃呃好乱
拿样例举例子：
可以把一条线路看作一个点，然后与站厅连接
但是这样点还是太多了，跑不了
这时候滚木 d 就发挥用处了
可以跑 d 个单源最短路，这样点的个数就是 n 个
算了一下 时间大概过不了
如果在一开始就跑一个全源的 floyd 好像可以过
理论达成 实践开始 

4：50 p.m. 经过1.5h的打代码与 debug 时间，终于打完了！ 
可惜的是最后两个大样例被卡了0.0几，不知道 ccf 的评测机能不能跑快一点 

5：07 p.m. 加了个快读卡过去了嘿嘿 

时间复杂度：O(n^3)
难度：green ~ Qing 
*/
