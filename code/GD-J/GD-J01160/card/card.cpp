#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long LL;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, a[N], ans[N], m, f[N], b[M], c[N];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; i--){
		b[a[i]] = max(i, b[a[i]]);
	}
	for (int i = 1; i <= n; i++){
		f[i] = b[a[i]] + 1;
	}
	for (int i = 1; i <= n; i++) c[i] = 1;
	for (int i = 1; i <= n; i++){
		ans[a[i]] += c[i];
		c[f[i]] += c[i];
	}
	for (int i = 1; i <= m; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}
