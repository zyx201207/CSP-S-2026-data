#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],c[500010],sum[500010],flag=1,luogu_uid=1269539;
int check(int x) {
	int res=2e18;
	for(int i=1;i+x-1<=n;i++)
		res=min(res,a[i+x-1]*x-sum[i+x-1]+sum[i-1]);
	return res<=m;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];sort(a+1,a+n+1);sum[1]=a[1];
	if(n==2) return cout<<((abs(a[1]-a[2])<=m)?2:1),0;
	for(int i=2;i<=n;i++) c[i]=abs(a[i]-a[i-1]),sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r) {
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}cout<<ans;
	return 0;
}
//100+100+0+0?
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
