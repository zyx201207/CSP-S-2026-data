#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s[500005];
bool check(int x){
	int res=1e18;
	for(int i=x;i<=n;i++)
		res=min(res,a[i]*x-(s[i]-s[i-x]));
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int l,r,mid;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	l=1;
	r=n;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%lld",r);
	return 0;
}
