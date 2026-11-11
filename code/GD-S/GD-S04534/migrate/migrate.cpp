#include <bits/stdc++.h>
#define int long long
#define Blackdream1853 return
#define code 0
using namespace std;
const int N=5001;
int _, T, n, d, a[N], ans;
vector <int> g[N];
int dis[N][N];
int cnt(int x,int y) {
	for (int i=x;i<=y;i++)
		for (int j=0;j<=y-x;j++) dis[i][j]=0;
	dis[x][0]=1;
	for (int i=x;i<y;i++)
		for (int j=y-x;j;j--) {
			if (!dis[i][j-1]) continue;
			for (int z:g[i]) {
				if (z<=y) dis[z][j]+=dis[i][j-1];
				else break;
			}
		}
	for (int i=0;i<=y-x;i++)
		if (dis[y][i]) return dis[y][i];
	return 0;
}
void solve() {
	cin >> n >> d, ans=0;
	for (int i=1;i<=n;i++) g[i].clear();
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		for (int j=1;j<i;j++)
			if (a[i]-a[j]<=d) g[j].push_back(i);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (cnt(i,j)==2) ans++;
	cout << ans << '\n';
}
signed main(void) {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> _ >> T; while (T--) solve();
	Blackdream1853 code;
}
/*
给出长度为n的数组x,和一个d
保证x[i]<x[i+1]
若|x[i]-x[j]|<=d,那么i和j之间有连边
某条从i到j的路径长度定义为经过的边数
现在,对于每对(i,j),i<j
若从i到j的长度最短的路径恰好有两条,那么贡献为1
求贡献之和
多测,sum(n)<=2e6, 1<=d<=2e18, |x[i]|<=1e18

这是一个好问题
n很大,不能直接连边,而且大概率是O(n)的解法
观察样例,对于不连通的若干块直接分开
此时保证每个连通块内的点都互相可达
然后我们可以证明,发生双路径的只会是在4个点间
称这四个点为abcd
此时,对于任意两个点x和y,其有贡献当且仅当
x在a左边,且从x开始必须经过a才能到b
y在d右边,且从y开始必须经过d才能到c
此时x和y产生贡献
问题来了,怎么求abcd,怎么求xy,怎么去重
对于abcd,可以发现在下面这组数据中,是可以不连续的
5 4
2 4 6 7 8
此时{2,4,6,7}和{2,4,6,8}均合法
假设我们求出了abcd,还要求xy和去重,这并不好做
考虑转化最短路径和恰好两条这两个限制
可以发现,其实就是转化成了四个点
对于a和d,如果其中有若干个点
而且只有两个点是a和d都可以到的,那么就行
这个可以通过一个二分或者预处理很快地求出来
而且对于固定的a,合法的d会是一个范围
但是n有2e6,又只有1s时间,不是很可能
考虑对于每个点i,计算1到i-1有多少贡献
显然是经过一条链(可以是单点)
经过一个双路径,再经过一条链(可以是单点)
然后求其能够到达多少点
很显然,对于其前面一直到第一个双路径上的点,均不行
对于其前面第二个双路径及以前的点也不行
这是因为,经过其的最短路径不止一条
但你发现并不是这样
考虑n^2或n^3
首先可以通过n^2的枚举找到所有合法的点
然后考虑进行dfs,一直往同一方向找,找到就跳
然后记录结果
这是n^3的,有24分
0 1
6 12
-10 -6 -2 2 6 10
----1
0 1
6 6
-5 -3 -1 1 3 5
----1
*/
