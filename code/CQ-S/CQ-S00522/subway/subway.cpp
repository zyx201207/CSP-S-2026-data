#include<bits/stdc++.h>
using namespace std;
namespace Luo_ty{
	const int MAXN = 505, MAXM = 500005;
	const long long inf = 0x7fffffffffffffff / 2;
	long long f[MAXN][MAXN];
	int w[MAXM];
	struct walk{
		int id, t;
	};
	vector<walk> sub[MAXM];
	inline int read(){
		int ans = 0;
		char ch = 'l';
		while(ch < '0' || ch > '9') ch = getchar();
		while('0' <= ch && ch <= '9'){
			ans = (ans << 3) + (ans << 1) + ch - '0';
			ch = getchar();
		}
		return ans;
	}
	int main(){
		int c, n, m, d, q;
		c = read();
		n = read();
		m = read();
		d = read();
		q = read();
//		scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				f[i][j] = inf;
			}
			f[i][i] = 0;
		}
		//地铁口到站厅的时间 
		for(int i = 1;i <= m;i++) w[i] = read();//scanf("%d", &w[i]);
		//每条地铁线路 
		for(int i = 1, k, a, t;i <= n;i++){
			k = read();
//			scanf("%d", &k);
			for(int j = 1;j <= k;j++){
				a = read();
				t = read();
//				scanf("%d%d", &a, &t);
				for(walk r : sub[a]){
					f[i][r.id] = min(f[i][r.id], 1ll * t + r.t);
					f[r.id][i] = f[i][r.id]; 
				}
				sub[a].push_back((walk){i, t});
			}
		}
		for(int k = 1;k <= n;k++){
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]); 
				}
			}
		}
		for(int i = 1, x, y;i <= q;i++){
			x = read();
			y = read();
//			scanf("%d%d", &x, &y);
			long long ans = inf;
			for(walk s : sub[x]){
				for(walk t : sub[y]){
					ans = min(ans, s.t + f[s.id][t.id] + t.t);
				}
			}
			printf("%lld\n", w[x] + ans + w[y]);
		}
//		while(1);
		return 0;
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	return Luo_ty::main();
}
//24MB 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
