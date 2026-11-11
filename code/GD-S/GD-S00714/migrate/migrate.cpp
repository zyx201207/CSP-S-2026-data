#include <bits/stdc++.h>
#define int long long
using ll = long long;
const int MAX = 5e5 + 5;

int c,t;
int n;
ll d,x[MAX];

void sol1(){
	int ans = 0;
	// 每一个点最远跳到哪里是一定的，所以可以预处理
	std::vector<int> nxt(n + 1);
	for(int i = 1;i <= n;i++){
		int pos = std::upper_bound(x + i + 1,x + n + 1,x[i] + d) - x - 1;
		nxt[i] = pos;
	}
	auto bfs = [&](int s) {
		std::vector<int> f(n + 1),dis(n + 1,-1);
		std::queue<int> q;
		for(q.push(s),dis[s] = 0;!q.empty();){
			auto u = q.front();q.pop();
			for(int i = u + 1;i <= nxt[u];i++) {
				if(dis[i] == -1){
					dis[i] = dis[u] + 1;
					f[i]++;
					q.push(i);
				}
				else{
					if(dis[i] == dis[u] + 1)
						f[i]++;
				}
			}
		}
		for(int i = s + 1;i <= n;i++)
			if(f[i] == 2) ans++;
	};
	for(int i = 1;i <= n;i++)
		bfs(i);
	std::cout << ans << '\n';
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::cin.tie(0) -> sync_with_stdio(0);

	std::cin >> c >> t;
	while(t--){
		std::cin >> n >> d;
		for(int i = 1;i <= n;i++)
			std::cin >> x[i];
		sol1();
	}
	return 0;
}
/*
梁皓然 于2026年10月31日16：51满分抵达这里！！！
好了好了，已经两题了，开始打暴力了

给定若干个序列，跳跃最远可以从 i 跳到最后一个 x_j <= x_i + d 的位置
那么每个位置最远可以跳到什么位置这个是固定的
有点像某种倍增？
先从 1 开始考虑吧
最短路径就是跳的次数，也许可以按照跳跃次数分类？
1 跳一次可以到 [1,j] x_j <= x_i + d
哎？那么[1,j] 每个点跳一次也会有一个区间？？？
想想什么时候会有恰好两条最短路？

首先，只跳一次是不可能有两条最短路的，因为两个点直达一定不会有其他方案
跳两次？
两个区间l1,r1,l2,r2
满足l2 = r1 - 1
然后接下来的区间都必须要恰好 r1 - l2 了，不然乘法原理就把答案搞多了

*/