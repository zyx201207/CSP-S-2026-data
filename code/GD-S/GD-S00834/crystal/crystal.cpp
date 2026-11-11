#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5+5;
int n,m,a[maxn],sum[maxn];
bool check(int x){
	int ret = 1e18+5;
	for(int i = x;i <= n;i++){
//		int res = 0;
//		for(int j = 1;j < x;j++) res += a[i] - a[i - j];
		int res = a[i] * (x - 1) - sum[i-1] + sum[i - x];
		ret = min(ret,res);
	}
	return (ret <= m);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++) sum[i] = sum[i-1] + a[i];
	int l = 1,r = n,ans = 0;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)) ans = mid,l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n",ans);
	return 0;
}
