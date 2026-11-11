#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long ans=INT_MIN;
	for (int i=1;i<=n;i++)
	{
		long long v=m;
		long long sum=1;
		for (int j=i-1;j>=1;j--)
		{
			if (v>=a[i]-a[j])
			{
				v-=a[i]-a[j];
				sum++;
			}
			else
			{
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout <<ans;
	return 0;
}
