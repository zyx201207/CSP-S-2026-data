//贵阳市第一中学 谷佳鸿 GZ-S00130 
/*
migrate
对于一对双岛u,v，从u,v的路径可以分为两端
L1:u -> x 只有一条路径 
L2:x -> y 有两条路径，但是这两条路径无公共前缀、后缀 
L3:y -> v 只有一条路径 
同时满足x,y是必经岛即wx+1 - wx-1 > d, wy+1 - wy-1 > d

经过推导，我们发现L2距离最大为2
即到x,y距离都<=d的点恰有2个 
设pos[x]表示x最后一个直接到达的点，pre[x]表示第一个x直接到达的点
即pos[x] - pre[y] + 1 == 2

预处理以x结尾的L1,以y结尾的L3的数量
我们就可以得到40分了 
先检验一番我们对不对，再导 

*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int  pre[maxn], pos[maxn], opre[maxn], opos[maxn];
long long a[maxn];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	int c, T;
	scanf("%d%d", &c, &T);
	while(T--){
		int n;
		long long d;
		scanf("%d%lld", &n, &d);
		for(int i = 1;i <= n; i++){
			scanf("%lld", &a[i]);
		}
		for(int i = 1;i <= n; i++){
			pre[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
			pos[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
		}
		a[0] = a[n + 1] = a[n + 2] = pos[n + 1] = pos[n + 2] = pre[n + 1] = pre[n + 2] = pos[0] = pre[0] = 0;
		sort(a + 1, a + n + 1);
//		for(int i = 1;i <= n; i++) printf("%lld ", a[i]); printf("\n");
		for(int i = 1;i <= n; i++){
			if(a[i] - a[i - 2] <= d || pos[i - 2] - pre[i] + 1 != 1) opre[i] = i - pre[i] + 1;
			else opre[i] = opre[i - 1] + 1;
		}
		for(int i = n;i >= 1; i--){
			if(a[i + 2] - a[i] <= d || pos[i] - pre[i + 2] + 1 != 1) opos[i] = pos[i] - i + 1;
			else  opos[i] = opos[i + 1] + 1;
		}
//		for(int i = 1;i <= n; i++) printf("%d ", pre[i]); printf("\n");
//		for(int i = 1;i <= n; i++) printf("%d ", pos[i]); printf("\n");
//		for(int i = 1;i <= n; i++) printf("%d ", opre[i]); printf("\n");
//		for(int i = 1;i <= n; i++) printf("%d ", opos[i]); printf("\n"); 
		long long ans = 0;
		for(int x = 1;x <= n; x++){
			for(int y = x + 1;y <= n; y++){
				if(a[y] - a[x] <= d || pos[x] - pre[y] + 1 != 2) continue;
				long long res = 1;
				if(a[x + 1] - a[x - 1] > d) 
					res *= opre[x];
				if(a[y + 1] - a[y - 1] > d)
					res *= opos[y];
//				printf("%d %d %lld\n", x, y, res);
				ans += res;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
