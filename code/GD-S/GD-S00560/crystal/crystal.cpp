#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500005],s[500005];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;++i)
		scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;++i)
		s[i] = s[i - 1] + a[i];
	int r = 1;
	for(int l = 1;l <= n;++l){
		while(r <= n && a[r] * (r - l + 1) - s[r] + s[l - 1] <= m)
			r++;
		ans = max(ans,r - l);
//		printf("[%lld : %lld] : {%lld, %lld}\n",l,r - 1,r - l,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
n log n

*/
