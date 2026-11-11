#include <bits/stdc++.h>
#define N 200050
#define ll long long
using namespace std;
ll m, n, i, j, k, a[N], t, w, l, r, ans;
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for(i=1; i<=n; i++){
		scanf("%lld %c", &a[i], &c[i]);
		m += a[i];
	} 
	m >>= 1, i = 0, j = n+1;
	while(t < m||w < m){
		if(l == 0&&t < m) l = min(m-t, a[++i]), t += a[i];
		if(r == 0&&w < m) r = min(m-w, a[--j]), w += a[j];
		if(c[i] != c[j]) ans += min(l, r);
		if(l >= r) l -= r, r = 0ll;
		else r -= l, l = 0ll;
	}
	printf("%lld", ans);
	return 0;
}
