#include <iostream>
#include <algorithm> 
using namespace std;

typedef long long lld;
const lld maxn = 5e5 + 5;
lld n, m, a[maxn], ans = 1;
lld sum[maxn];

lld solve(lld x){
	return (x-1) * a[x] - sum[x-1];
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
	lld l = 1, r = n;
	while(l <= r){
		lld mid = l + r >> 1;
		if(solve(mid) > m) r = mid - 1;
		else l = mid + 1;
	}
	ans = l - 1;
	cout << max(ans, 1ll);
	return 0;
}
