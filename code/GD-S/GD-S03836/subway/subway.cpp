//估分：80~92，不错！ 如果CCF少爷机这题能A 
//简单题 
#include<bits/stdc++.h>
using namespace std;
#define int long long
//显然如果你乘坐地铁那么对于所有地铁的站点都是一样的时间，不如考虑从第i个地铁转移到第j个地铁要多少步行时间 
const int N = 505 , M = 5e5 + 5;
int n , m , d , q , w[M] , dp[N][N];
//int ti[M][N];//第i个站台去第j个地铁需要第步行时间 
vector<pair<int , int>> have[M];//第i个站台有哪些列车经过，它们从站厅到站台所需要的时间 
#define File(x) freopen(x".in" , "r" , stdin);freopen(x".out" , "w" , stdout)
//复杂度:O(n^3+md^2)，会A吗 
signed main(){
	File("subway");
//	memset(dp , 0x3f , sizeof(ti));
	memset(dp , 0x3f , sizeof(dp));
	int c;
	scanf("%lld %lld %lld %lld %lld" , &c , &n , &m , &d , &q);
	for(int i = 1;i <= m;i ++){
		scanf("%lld" , w + i);
	} 
	for(int i = 1;i <= n;i ++){
		int h;
		scanf("%lld" , &h);
		for(int j = 1;j <= h;j ++){
			int k , t;
			scanf("%lld %lld" , &k , &t);
//			ti[k][i] = t;
			have[k].push_back({i , t}); 
		}
	}
	for(int i = 1;i <= m;i ++){
		for(auto j : have[i]){
//			printf("%lld " , j.first);
			for(auto k : have[i]){
				if(j.first == k.first) continue;
//				printf("!");
				dp[j.first][k.first] = dp[j.first][k.first] = j.second + k.second;
			}
		}
//		puts("");		
	}
	for(int i = 1;i <= n;i ++){
		dp[i][i] = 0;
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			for(int k = 1;k <= n;k ++){
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i = 1;i <= q;i ++){
		int x , y , need = 0x3f3f3f3f3f3f3f3f;
		scanf("%lld %lld" , &x , &y);
		for(auto j : have[x]){
			for(auto k : have[y]){
				need = min(dp[j.first][k.first] + j.second + k.second, need);
			}
		}
		printf("%lld\n" , need + w[x] + w[y]);
	} 
	return 0;
}
