#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 2000005;
int c, T, n, mn_dis, mn_cnt;

ll D, a[N];

// 从点 x 出发 到达 y 的最短路 
void dfs(int x, int y, int dis) {
//	cout<<x<<' '<<dis<<endl;
	if(dis > mn_dis) return ; // 剪枝 
	if(x == y) {
		if(dis < mn_dis) {
			mn_dis = dis;
			mn_cnt = 1;
		} else if(dis == mn_dis) {
			++mn_cnt;
		}
		return ;
	}
	for(int i=1; i<=n; ++i) {
		if(i!=x && abs(a[i]-a[x]) <= D) {
			dfs(i, y, dis+1);
		}
	}
}

void sol() {
	scanf("%d%lld", &n, &D);
	for(int i=1; i<=n; ++i) {
		scanf("%lld", &a[i]);
	}
	if(n == 1) {
		puts("0");
		return ;
	}
	if(D == 0) {
		puts("0");
		return ;
	}
	if(c == 11 || c == 12) {
		ll di = a[2]-a[1]; // 数据保证了 di!=0 
		if(D <= di) {
			puts("0");
			return ;
		}
		ll tot = D/di;
		if(2*tot > n) {
			puts("0");
			return ;
		}
		printf("%lld\n", n-2*tot+1);
		return ;
	}
	ll ans = 0;
	for(int u=1; u<n; ++u) {
		for(int v=u+1; v<=n; ++v) {
//			cout<<u<<","<<v<<":\n";
			mn_dis = n+1, mn_cnt = 0;
			dfs(u, v, 0);
			if(mn_cnt == 2) ++ans;
		}
	}
	printf("%lld\n", ans);
}

int main() {
//	freopen("C:\\Users\\XDFZ\\Desktop\\migrate\\migrate4.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while(T--) sol();
	return 0;
} /*
第四个是特殊性质A 

特殊性质A：tot = D/间隔 向下取整 
那么只有经过点数为 2tot 的才是合法路径 
答案为 n-2tot+1 

n<=9：枚举点对，求最短路，看有多少条。 
从 u 到 v，u<v，显然走比 v 大的点最优……？ 
走别的其实也可以。比如先走到比 u 小的再绕到比 u 大的，其实也算作一种方案。。 

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/ 
