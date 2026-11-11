#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+1+n);
	int l=1,r=0;
	long long s=0;
	while(r<n)
	{
		r++;s+=(r-l)*(a[r]-a[r-1]);
		while(s>m)s-=a[r]-a[l++];
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
//14:40 completed
//14:43 tested
