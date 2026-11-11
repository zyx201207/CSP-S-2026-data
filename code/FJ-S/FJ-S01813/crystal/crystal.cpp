#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n;
long long m,a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	s[0]=0;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int ans=1;
	for(int l=1,r=1;r<=n;r++)
	{
		if(a[r]-a[l]>m)
		{
			l++;
			r--;
			continue;
		}
		long long sum=(r-l+1)*a[r]-(s[r]-s[l-1]);
		if(sum<=m)
			ans=max(ans,r-l+1);
		else
			l++;
	}
	printf("%d",ans);
	return 0;
}