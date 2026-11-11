#include <bits/stdc++.h>
#define int long long
#define Blackdream1853 return
#define code 0
using namespace std;
const int N=501, M=5e5+1, D=21;
int _, n, m, d, q, w[M];
int k[M];
int p[M], c[M][D], s[M][D];
int dis[N][N];
/*
w表示出入站时间
k表示每条线路经过站数
p表示每个站有多少条线路经过
c表示每个站经过的线路是什么
s表示每个站经过的线路到站厅的时间
*/
signed main(void) {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> _ >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> w[i];
	for (int i=1;i<=n;i++) {
		cin >> k[i];
		int len=k[i], a, t;
		for (int j=1;j<=len;j++) {
			cin >> a >> t;
			c[a][++p[a]]=i;
			s[a][p[a]]=t;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int i=1;i<=m;i++) {
		int len=p[i];
		for (int x=1;x<=len;x++) for (int y=1;y<=len;y++) {
			int u=c[i][x], v=c[i][y];
			dis[u][v]=min(dis[u][v],s[i][x]+s[i][y]);
		}
	}
	for (int mid=1;mid<=n;mid++)
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
			dis[i][j]=min(dis[i][j],dis[i][mid]+dis[mid][j]);
	while (q--) {
		int x, y, ans=1e18+1;
		cin >> x >> y;
		for (int i=1;i<=p[x];i++) for (int j=1;j<=p[y];j++)
			ans=min(ans,dis[c[x][i]][c[y][j]]+s[x][i]+s[y][j]);
		cout << ans+w[x]+w[y] << '\n';//注意这里的x和y,i和j
	}
	Blackdream1853 code;
}
/*
有若干个量
首先给出n个对点,每对点之间有往返时间
记其中一个点为u,另一个点为v
然后给出m个线路,每个线路有固定经过的若干个v点
从线路走到v点需要t的时间,保证一条线路不经过两次同一点
保证每个v点最多有d条线路,且整个图连通
有q次询问,每次从某一点到达另一点,途中可能进行换乘
换乘的时间为从线路到v点再到另一线路
求出每个出行计划的最小换乘时间,加上起点终点的uv往返时间
m<=sum(ki)<=5e5, n<=500, d<=20, q<=1e5
单个时间值域在1e9

观察到问题将点设置为m,线路设置为n,是有点奇怪的
既然是多源最短路,那大概是把线路当点,把换乘当边,然后floyed
考虑把每条线路当作点,那么每个站就需要处理若干个点的信息
每个站,每两个点进行一次连边
然而这样的时间复杂度过高
考虑能否将站厅视作一个点,然后每个点向其连边
然而这会导致点数过多,并不好
5e5*20*20是2e8,放在500*500的图上不知道能不能过
对于每条线路,会经过若干个点
一个点视作20条连边,而所有点的和是5e5
所以不需要2e8,只需要1e7,那就行了
然而最后的问题是到站的,而不是到边的
所以每个询问还需要查询每条到其的线路之间的最优解
询问只有1e5,乘个400来到4e7,能过
预计用时45分钟,数据比较复杂,记得检查格式,有时间对拍
这个输入量大得离谱,不开ios是两秒多,开了是0.3秒
然后subway6是d大时间小,subway7是时间大t小,可能需要融合一下
完成时间 16:00
*/
