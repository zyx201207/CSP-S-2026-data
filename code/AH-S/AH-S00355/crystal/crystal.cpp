#include "bits/stdc++.h" 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[100001],ans = 1;
	std::cin >> n >> m;
	for (long long i = 1;i <= n;i++)
	{
		std::cin >> a[i];
	}
	std::sort(a+1,a+n+1);
	for (long long i = 2;i <= n;i++)
	{
		long long sum = m,num = 1;
		for (int j = i-1;j >= 1;j--)
		{
			sum -= a[i]-a[j];
			if (sum >= 0) num ++;
			else break;
		}
		ans = std::max(ans,num);
	}
	std::cout << ans;
	return 0;
}
