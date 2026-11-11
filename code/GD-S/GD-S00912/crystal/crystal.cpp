#include<bits/stdc++.h>
using namespace std;

long long a[500005];
long long n,m;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	bool A = true,B = true;
	for(int i = 1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
		if(a[i] != i)A = false; 
		if(i >= 3)
		{
			if(a[i] - a[i-1] != a[i-1] - a[i-2])B = false;
		}
	}
	if(A || B)
	{
		long long can = m,cnt = 1;
		for(int j = n-1; j>=1; j--)
		{
			if(can - (a[n] - a[j]) >= 0)
			{
				can -= a[n]-a[j];
				cnt++;
			}
			else break;
		}
		printf("%lld",cnt);
		return 0;
	}
	sort(a+1,a+n+1);
	long long ans = 1;
	for(int i = n; i>=1; i--)
	{
		long long can = m,cnt = 1;
		for(int j = i-1; j>=1; j--)
		{
			if(can - (a[i] - a[j]) >= 0)
			{
				can -= a[i]-a[j];
				cnt++;
			}
			else break;
		}
		ans = max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
