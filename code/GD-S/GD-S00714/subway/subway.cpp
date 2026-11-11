#include <bits/stdc++.h>
using ll = long long;
const int N = 5e2 + 5;
const int M = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

// 测试点编号c 地铁线路数n 地铁站数m 每个地铁站最多被几条线路经过d 以及出行计划数q
int c,n,m,d,q;
// 表示从地铁口走到站厅的时间
ll w[M];
// p_i 的每个元素(a,b)表示从站厅 i 到线路 a 的站台用时 b
std::map<int,ll> p[M];
std::vector<int> bin[M];
ll f[N][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::cin.tie(0) -> sync_with_stdio(0);

	memset(f,0x3f,sizeof(f));
	std::cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		std::cin >> w[i];
	for(int k,i = 1;i <= n;i++) {
		std::cin >> k;
		f[i][i] = 0;
		for(int a,b,j = 1;j <= k;j++){
			// a 表示站厅，b 表示从站厅到线路 i 的站台的用时
			std::cin >> a >> b;
			p[a][i] = b;
			bin[a].push_back(i);
		}
	}

	//枚举站厅，然后给这个站厅所链接的每一个线路的站台连边
	for(int i = 1;i <= m;i++){
		for(auto u = p[i].begin();u != p[i].end();u++){
			for(auto v = p[i].begin();v != p[i].end();v++){
				auto [plat1,tim1] = *u;
				auto [plat2,tim2] = *v;
				f[plat1][plat2] = std::min(f[plat1][plat2],tim1 + tim2);
			}
		}
	}

	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				f[i][j] = std::min({f[i][j],f[i][k] + f[k][j]});

	while(q--){
		int x,y;
		std::cin >> x >> y;
		ll ans = INF;
		for(auto i : bin[x])
			for(auto j : bin[y]){
				ll res = w[x] + w[y] + p[x][i] + p[y][j] + f[i][j];
				ans = std::min(ans,res);
			}
		std::cout << ans << '\n';
	}
	return 0;
}
/*
看起来是某种最短路
最短路题关键在于建图，看看图怎么建
关键注意：坐地铁是不耗时间的，然后线路数是非常少的只有 500
而且从地铁口到地铁口，真正要计算的只是换乘的时间，口的时间是可以直接得到的
难道是floyd？？？
对，是这样的，因为询问是 1e5 次的询问，也就是说我们需要很高效地回答任意两点的最短路
对了，每个地铁口可能属于多条线路，我们可以枚举这个，这个是可以接受的，因为 d<=20

所以我们要建的是关于地铁线的图，考虑两个地铁线之间怎么建边？
考虑每一个地铁站归属于哪几个线路，然后这些线路两两建边

然后跑floyd，查询就是查询地铁所属的线路
*/