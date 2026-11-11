#include<bits/stdc++.h>
using namespace std;
namespace Luo_ty{
	const int MAXN = 2000005;
	long long x[MAXN];
	int f[MAXN];
	long long g[MAXN], s[MAXN];
	inline long long read(){
		long long ans = 0;
		int op = 1;
		char ch = getchar();
		if(ch == '-') op = -1;
		while(ch < '0' || ch > '9') ch = getchar();
		while('0' <= ch && ch <= '9'){
			ans = (ans << 3) + (ans << 1) + ch - '0';
			ch = getchar();
		}
		return ans * op;
	}
	int main(){
		int c, T;
		c = read();
		T = read();
//		scanf("%d%d", &c, &T);
		int n;
		long long d;
		while(T--){
			n = read();
			d = read();
//			scanf("%d%lld", &n, &d);
			for(int i = 1;i <= n;i++){
				x[i] = read();
//				scanf("%lld", &x[i]);
			}
			if(c == 11 || c == 12){
				if(n == 1) puts("0");
				else{
					long long tmp = x[2] - x[1], bas = d / tmp;
					if(bas < 2) puts("0");
					else{
						int len = 2 * bas - 1;
						printf("%d\n", max(0, n - len));
					}
				} 
				continue;
			}
			int ans = 0;
			for(int l = 1;l < n;l++){
				int L = l, R = l;
				s[l] = 0;
				for(int r = l + 1;r <= n;r++){
					if(x[r] - x[r - 1] > d) break;
					f[r] = g[r] = 0;
					if(x[r] - x[l] <= d){
						f[r] = 1;
						g[r] = 1;
						s[r] = s[r - 1] + g[r];
						continue;
					}
					while(x[r] - x[L] > d) L++;
					while(f[R + 1] == f[L] && R + 1 < r) R++;
					f[r] = f[L] + 1;
					g[r] = s[R] - s[L - 1];
					s[r] = s[r - 1] + g[r];
					if(g[r] == 2) ans++;
				}
			}
			printf("%d\n", ans);
			//Çå¿Õ 
		}
//		while(1);
		return 0;
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	return Luo_ty::main();
}
//55MB
/*
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

0 1
5 3
-3 0 2 3 4
*/
