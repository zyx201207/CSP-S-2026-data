#include <bits/stdc++.h>
using namespace std; typedef long long ll;
const int N = 500005;
int n,ans; ll a[N],m;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1); int l = 1; ll k = 0;
	for (int r = 1;r <= n;r++) {
		k += (r-l)*(a[r]-a[r-1]);
		while (k > m) k -= a[r]-a[l],l++;
		ans = max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
