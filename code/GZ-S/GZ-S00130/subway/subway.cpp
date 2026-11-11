//贵阳市第一中学 谷佳鸿 GZ-S00130 
/*
subway
把每一条路线视作点，就可以跑Floyd

我们预处理出每一个站有哪些路线经过
然后把路线连起来，O(md^2)
边可能比较多，但是注意到Σk<=1e5
实际上的边会相对少一些 
然后跑一遍，对于每次询问u,v
找到u和v分别有哪些路线经过
枚举路线的对数(最多400)
总而言之O(d^2 (m + q) + n^3) 

大样例都过了，最多1.4s 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 505, maxm = 5e5 + 5;
long long inf = 1e18;
struct CROSS{
	int to, w;
};
vector<CROSS> cross[maxm];
int w[maxm];
long long dis[maxn][maxn];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1;i <= n; i++){
		int k;
		scanf("%d", &k);
		for(int j = 1;j <= k; j++){
			int a, t;
			scanf("%d%d", &a, &t);
			cross[a].push_back({i, t});
		}
	}
	memset(dis, 0x7f, sizeof(dis));
//	printf("%lld\n", dis[0][0]);
	for(int i = 1;i <= n; i++) dis[i][i] = 0;
	for(int i = 1;i <= m; i++){
		for(auto c1 : cross[i]){
			int to1 = c1.to, w1 = c1.w;
			for(auto c2 : cross[i]){
				int to2 = c2.to, w2 = c2.w;
				if(to1 == to2) continue;
				dis[to1][to2] = dis[to2][to1] = min(dis[to1][to2], (long long) w1 + w2);
			}
		}
	}
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= n; j++){
			for(int k = 1;k <= n; k++){
				if(dis[i][k] > inf || dis[k][j] > inf) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
//	for(int i = 1;i <= n; i++){
//		for(int j = 1;j <= n; j++){
//			if(dis[i][j] < 0) printf("fushu");
//		}
//	}
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		long long ans = inf;
		for(auto c1 : cross[x]){
			int to1 = c1.to, w1 = c1.w;
			for(auto c2 : cross[y]){
				int to2 = c2.to, w2 = c2.w;
				ans = min(ans, (long long) w[x] + w1 + w[y] + w2 + dis[to1][to2]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
