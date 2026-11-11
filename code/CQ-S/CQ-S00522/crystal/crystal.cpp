#include<bits/stdc++.h>
using namespace std;
namespace Luo_ty{
	const int MAXN = 500005;
	long long a[MAXN], b[MAXN];
	int main(){
		int n;
		long long m;
		scanf("%d%lld", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		int ans = 0, lst = 1;
		for(int i = 1;i <= n;i++){
			b[i] = b[i - 1] + a[i];
			while(a[i] * (i - lst + 1) - (b[i] - b[lst - 1]) > m) lst++;
			ans = max(ans, i - lst + 1);
		}
		printf("%d", ans);
//		while(1);
		return 0;
	}
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	return Luo_ty::main();
}
//8MB
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
