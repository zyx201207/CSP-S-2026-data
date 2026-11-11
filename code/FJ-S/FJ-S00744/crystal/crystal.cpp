#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 1;
int n; ll m, a[maxn];
int main(){
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i < n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 1;
	for(ll l = 1, r = 2, need = 0; r <= n; r++){//a[l,r]经过m次都能变成a[r]
		need += (r - l) * (a[r] - a[r - 1]);
		while(need > m && l < r){
			need -= a[r] - a[l];
			l++;
		}ans = max(ans, (int)(r - l + 1));
	}printf("%d", ans);
	return 0;
}
