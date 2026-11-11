#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000009],b[1000009],cnt[1000009];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		++cnt[a[i]];
	}
	for(int i=n;i>=1;--i)
	{
		if(b[a[i]]==0)b[a[i]]=i;
	}
	for(int i=1;i<n;++i)
	{
		if(b[a[i]]==i)
		{
			cnt[a[i+1]]+=cnt[a[i]];
		}
	}
	for(int i=1;i<=m;++i)
	{
		printf("%lld ",cnt[i]);
	}
	return 0;
}
