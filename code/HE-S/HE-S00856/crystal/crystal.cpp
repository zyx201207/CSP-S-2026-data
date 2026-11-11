#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,M,a[500010],p[500010];
signed main() {
	freopen("crystal.in","r",stdin); freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> M; for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+1+n); for(int i = 1; i <= n; i++) p[i] = a[i]+p[i-1];
	int l = 0,ans = 0; for(int i = 1; i <= n; i++) {
		while(l < i && (i-l)*a[i]-(p[i]-p[l]) > M) l++;
		ans = max(ans,i-l);
	} printf("%lld\n",ans);
	return 0;
}
