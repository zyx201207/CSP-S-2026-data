#include <bits/stdc++.h>
#define N 200050
#define ll long long
using namespace std;
ll m, n, i, j, k, a[N], ans, b[N];
void dfs(ll k){
	if(k < 0) return;
	ll l = 0ll, i;
	for(i=1; i<=n; i++){
		if(a[i] & (1<<k)) b[++l] = a[i];
	}
	if(l < m){
		dfs(k-1);
		return;
	}
	for(i=1; i<=l; i++) a[i] = b[i];
	ans |= 1<<k, n = l, dfs(k-1);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	dfs(30);
	printf("%lld", ans);
	return 0;
}
