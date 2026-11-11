/*The code is from koukilee(luogu@)*/
#include <bits/stdc++.h>

typedef long long i64; typedef int i32;

const i64 MAXN = 1010100, INF = 992010081220091007, N = 510;

inline void read (i64 &x) {scanf ("%lld", &x);}
inline void print (i64 x) {printf ("%lld", x);}
inline void put (i64 x) {print (x); putchar ('\n');}

/*
	加油
	感觉是一个图论建模题？
	注意到n比较小，但是q比较大，所以估计应该是一个 qn 的题目
	地铁口到站厅不用考虑吧比较必须从那里进去出来，所以可以最后加上，不用管吧
	假如我想换乘，emm
	有点意思，这个 d 肯定不是吃白饭的
	主要是通过一些枢纽站来互相转移，我们考虑把贡献转化一下，好像也不太行
	注意到我们每次真正需要换乘的次数是不超过n的 
	主要是可能换乘很多次
	我们考虑缩点吗？（好像不对，块内的点不能互相移动的
	假设你在一条线上，等等我们不考虑点转移，我们考虑线转移
	我们从一条线，想要到达另一条线，我们可以预处理出最少的时间
	只要我们知道所有可能的线线转移，我们就可以floyd，然后光速预处理最后回复即可
	那么我们这个时候考虑怎么处理这个线的问题，对于在同一条线上的点，
	我们考虑如果他不止在一条线上的话，我们就更新一下最值即可 
	k，感觉真有可能是对的，加油啊！！！来吧
	欸，那么d保证了什么呢？
	哦，应该是保证了处理的时候遍历不会炸掉，好正确啊！ 
	哦对了，最后从哪一个站点出来也是不确定的，这里也是d的用处之一 
	不对啊，两点之间能互相到，那么两条线路也一定可以啊（？ 
	nice过了！！！发了点小糖，nice 15:33，我看看时间超美超
	极限数据0.7s感觉没问题了 
	加油，才过了一个小时，有很大希望啊，不对啊，我算了下时间好像最后一个包跑不过啊
	qn^2 好像有点慢，还是需要优化一下
	但是预处理也好象不太科学
	但是\sum <= 5e5的，那么平均能跑满的线只有2e4个点假如全问这些点，那么就是8e6左右的复杂度 
	其他的基本上是小喽啰，完全跑不满，但是如果这一块我们不预处理，可以问10 次左右其实差不多1e8+了不一定能跑满，这个再说吧，
	我先加一个预处理试试
	不对，根本预处理不了啊emmm就这样吧，应该能跑满的
	不对啊，复杂度算错了，应该完全不会有问题的（ 
*/

i64 c, n, m, d, q, a[MAXN], dis[N][N];
std::vector <std::pair <i64, i64>> L[MAXN], /*每条线路有哪些点*/
			G[MAXN]; /*每个点能到那些线路，然后时间*/

int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	read (c), read (n), read (m), read (d), read (q);
	
	for (i32 i = 1; i <= m; i++)
		read (a[i]);
	
	for (i32 i = 1; i <= n; i++) {
		i64 al; read (al);
		
		while (al--) {
			i64 x, y; read (x), read (y);
			L[i].push_back ({x, y});
			G[x].push_back ({i, y}); /*能到达这条线*/
		}
	}
	
	__builtin_memset (dis, 0x3f, sizeof (dis));
	
	for (i32 i = 1; i <= n; i++)
		dis[i][i] = 0;
	
	for (i32 i = 1; i <= n; i++) { /*给每个线路开始连边*/
		for (auto it : L[i]) { /*把这个线路里面的点捞出来*/
			for (auto j : G[it.first]) { /*看看这个点到底可以到达那些线路呢*/
				if (i == j.first) continue;/*同一个站点不管了*/
				dis[i][j.first] = std::min (dis[i][j.first], it.second + j.second); 
				dis[j.first][i] = std::min (dis[j.first][i], it.second + j.second);/*进入另一条线路*/
			}
		}
	}
	
	/*开始floyd*/
	
	for (i32 k = 1; k <= n; k++)
		for (i32 i = 1; i <= n; i++)
			for (i32 j = 1; j <= n; j++)
				dis[i][j] = std::min (dis[i][j], dis[i][k] + dis[k][j]);
			
	while (q--) {
		i64 x, y, ans = INF; read (x), read (y);
		
		/*考虑进来和出去的线路*/
		for (auto i : G[x]) {
			for (auto j : G[y]) {
				ans = std::min (ans, i.second + dis[i.first][j.first] + j.second);
			}
		}
		
		put (ans + a[x] + a[y]);
	}		
	return 0;
}
