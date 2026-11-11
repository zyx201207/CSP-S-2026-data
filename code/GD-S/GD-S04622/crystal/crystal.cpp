#include <cstdio>
#include <algorithm>
#define N 500050
using namespace std;
long long i, j, k, n, m, a[N], l, r, ans, mid, res;
unsigned long long c[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(i=1; i<=n; i++) scanf("%lld", &a[i]);
	sort(a+1, a+i);
	for(i=1; i<=n; i++) c[i] = 1ull * c[i-1] + (a[i] - a[i-1]) * (i - 1);
	for(i=1; i<=n; i++){
		l = 1, r = i, ans = 1;
		while(l <= r){
			mid = (l + r) >> 1;
			if(c[i] - c[mid] - (a[i] - a[mid]) * (mid - 1) <= (unsigned long long)m)
				ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		res = max(res, i - ans + 1);
	}
	printf("%lld", res);
	return 0;
}
