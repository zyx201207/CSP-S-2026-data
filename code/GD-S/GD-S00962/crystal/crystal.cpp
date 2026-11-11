#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

//remember long long!

long long n, m;

long long a[500005];

long long diff[500005];

bool check(long long len)
{
	if(len == 1)
	{
		return true;
	}
	
	long long cost = 0;
	
	for(long long i = 1; i < len; i++)
	{
		cost += diff[i + 1] * i;
	}
	
	if(cost <= m)
	{
		return true;
	}
	
	for(long long l = 2; l + len - 1 <= n; l++)
	{
		cost -= (a[l + len - 2] - a[l - 1]);
		
		cost += (len - 1) * diff[l + len - 1];
		
		if(cost <= m)
		{
			return true;
		}
	}
	
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	std::sort(a + 1, a + n + 1);
	
	for(long long i = 1; i <= n; i++)
	{
		diff[i] = a[i] - a[i - 1];
	}
	
	long long l = 1, r = n;
	
	while(l + 1 < r)
	{
		long long mid = (l + r) >> 1;
		
		if(check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	
	cout << l;
}
