#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 500010;
LL n, l, r, mid, res = 1;
ULL m, s[N], s2[N];
LL a[N];
ULL check(LL x, LL y){
	return s2[y] - s2[x - 1] - (s[y] - s[x - 1]) * (x - 1);
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1;i < n;i++){
		if(a[i + 1] < a[i]){
			sort(a + 1, a + n + 1);
			break;
		}
	}
	for(int i = 1;i < n;i++){
		s[i] = s[i - 1] + a[i + 1] - a[i];
		s2[i] = s2[i - 1] + (a[i + 1] - a[i]) * i;
	}
	for(int i = 2;i <= n;i++){
		l = 1, r = i - 1;
		while(l < r){
			mid = l + r >> 1;
			if(check(mid, i - 1) > m) l = mid + 1;
			else r = mid;
		}
		res = max(res, i - mid + 1);
	}
	printf("%lld\n", res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
