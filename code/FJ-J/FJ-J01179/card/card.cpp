#include <bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	scanf("%lld %lld",&n,&m);
	long long a[40000];
	long long ans[400000];
	for (long long z=1;z<=n;z++)
	{
		scanf("%lld",&a[z]);
		ans[z]=0;
	}
	for (long long z=1;z<=n;z++)
	{
		long long s[400000];
		long long cnt[400000];
		for (long long i=1;i<=m;i++)
		{
			s[i]=0;
			cnt[i]=0;
		}
		for (long long i=z;i<=n;i++)
		{ 
			cnt[a[i]]++;
			if (cnt[a[i]]>1)
			{
				for (long long j=s[a[i]];j<i;j++)
				{
					cnt[a[j]]--;
				}
				s[a[i]]=i;
			}
			else if (cnt[a[i]]==1)
			{
				s[a[i]]=i;
			}
		}
		for (long long s=1;s<=m;s++)
		{
			if (cnt[s]) ans[s]++;
 		}
	}
	for (long long i=1;i<=m;i++) cout<<ans[i]<<" ";
}
