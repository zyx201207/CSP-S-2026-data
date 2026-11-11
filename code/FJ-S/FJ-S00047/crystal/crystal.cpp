#include<bits/stdc++.h>
using namespace std;

int n;
long long m, a[500005], sum[500005];

inline bool check(long long x){
	for(int i = x; i <= n; i++){
		if(a[i] * (x - 1) - (sum[i - 1] - sum[i - x]) <= m) return true;
	}
	return false;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	long long l = 1, r = n, ans = -1;
	while(l <= r){
		long long mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld", ans);
	return 0;
}
