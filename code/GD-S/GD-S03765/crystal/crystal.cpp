#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+5,mx=1e12;
int n,m,ans;
int a[N],s[N];
bool check(int x)
{
	int mn=INT_MAX;
	for(int i=x;i<=n;i++) mn=min(mn,a[i]*x-s[i]+s[i-x]);
	return mn<=m; 
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=mx;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
