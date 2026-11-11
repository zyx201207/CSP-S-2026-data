#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, r, l, d, a[500005], f[500005];
bool c(int x){
	int s=2e18;
	for(int i=x; i<=n; i++){
		if(x*a[i]-f[i]+f[i-x]<s) s=x*a[i]-f[i]+f[i-x];
	}
	return s<=m;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
	sort(a+1, a+1+n);
	for(int i=1; i<=n; i++) f[i]=f[i-1]+a[i];
	r=n, l=1;
	while(l<r){
		d=(l+r+1)/2;
		if(c(d)) l=d;
		else r=d-1;
	}
	printf("%lld", l);
	return 0;
}
