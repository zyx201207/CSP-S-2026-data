#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long long n, m;
long long bi(long long sum1,long long sum2)
{
	long long cc = 0;
	long long tm = 1;
	long long x = sum1;
	long long y = sum2;
	while(x >= 1 && y >= 1)
	{
		if(x%2 == 1 && y%2 == 1)
		{
			cc += tm;
		}
		tm *= 2;
		x /= 2;
		y /= 2;
	}
	return cc;
}
long long check(long long times, long long savetime,bool saving)
{
	long long andsum = 0;
	if(savetime >= m)
	{
		return andsum;
	}
	if(times >= a.size()-1)
	{
		return 0;
	}
	if(saving)
	{
		savetime++;
		if(savetime > 0)
		{
			andsum = bi(andsum,a[times]);
		}
		else
		{
			andsum = a[times];
		}
	}
	times++;
	andsum = max( bi(andsum,check(times,savetime,0)) , bi(andsum,check(times,savetime,1)) );
	return andsum;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long i;
	long long b;
	scanf("%lld %lld", &n, &m);
	for(i = 0;i < n;i++)
	{
		scanf("%lld", &b);
		a.push_back(b);
	}
	long long maxsum;
	maxsum = max(check(0,0,1),check(0,0,0));
	printf("%lld", maxsum);
	return 0;
}
