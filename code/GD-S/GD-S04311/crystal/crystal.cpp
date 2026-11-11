#include <bits/stdc++.h>
#define N 500050
#define ll long long 
using namespace std;
ll n, i, j, k, m, a[N], b[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for(i=1; i<=n; i++){
		b[i] = b[i-1] + a[i];
		while(k < i&&a[i]*(k+1)-(b[i]-b[i-k-1]) <= m) k++;
	}
	printf("%lld", k);
	return 0;
}

