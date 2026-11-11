#include <bits/stdc++.h>
using namespace std;
const int N = 2000050;
int n, m, i, j, k, L[N], R[N], f[N], g[N];
long long d, ans, e[N];
long long read(){
	long long res = 0, f = 1;
	char c = getchar();
	while(c < '-') c = getchar();
	if(c == '-') f = -1, c = getchar();
	while('0'<=c && c<='9') res = res*10+c-48, c = getchar();
	return f*res;
}
void work(){
	scanf("%d%lld", &n, &d);
	for(i=1; i<=n; i++) e[i] = read();
	for(j=i=1; i<=n; i++){
		while(j<i && e[i]-e[j]>d) j++;
		L[i] = j;
	}
	for(i=1; i<=n; i++){
		if(i == L[i]) f[i] = 0;
		else if(i<n && L[i+1]==L[i]) f[i] = i-L[i];
		else j = L[i], f[i] = i-j+f[j]-(j-L[j+1]);
//		printf("(%d %d %d)\n", i, L[i], f[i]);
	}
	for(j=i=n; i>=1; i--){
		while(i<j && e[j]-e[i]>d) j--;
		R[i] = j;
	}
	for(i=n; i>=1; i--){
		if(i == R[i]) g[i] = 0;
		else if(i>1 && R[i-1]==R[i]) g[i] = R[i]-i;
		else j = R[i], g[i] = j-i+g[j]-(R[j-1]-j);
//		printf("(%d %d %d)\n", i, R[i], g[i]);
	}
	for(ans=0, i=2; i<n-1; i++){
		j = i+1;
		if(L[j]>=i || R[i]<=j) continue;
		if(L[j+1]==L[j] || R[i-1]==R[i]) continue;
//		if(L[i]!=L[j] || R[i] != R[j]) ans += 1ll*(L[j+1]-L[j])*(R[i]-R[i-1]);
//		else ans += 1ll*(f[j]-(j-L[j+1]))*(g[i]-(R[i-1]-i));
		ans += 1ll*(L[i]==L[j]?f[j]-(j-L[j+1]):L[j+1]-L[j])*(R[i]==R[j]?g[i]-(R[i-1]-i):R[i]-R[i-1]);
//		printf("[%d %d %lld %d %d %d]\n", i, j, ans, f[j]-(j-L[j+1]), g[i], g[i]-(R[i-1]-i));
	}
	printf("%lld\n", ans);
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T;
	scanf("%*d%d", &T);
	while(T--) work();
	return 0;
}
