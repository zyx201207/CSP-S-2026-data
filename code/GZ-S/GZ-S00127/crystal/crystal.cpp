//GZ-S00127 ½ªÃú²Ó 
#include <algorithm>
#include <iostream>
#include <cstdio> 
using namespace std;
typedef long long LL;
const int MAXN = 5e5 + 5;
LL n, ans;
LL m, a[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	LL sum = 0;
	for(LL l = 1, r = 1; r <= n; r++){
		sum += a[r];
		while(l < r && m < (r - l + 1ll) * a[r] - sum) sum -= a[l], l++;
		ans = max(ans, r - l + 1ll);
	}
	cout << ans;
	return 0;
} 
