#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
pair<long long , char> a[N];
long long cz[N];//cz[i]记录第i块的结尾是哪一位 
long long ans = 0;

int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	scanf("%d" , &n);
	
	long long temp = 0;
	
	for(int i = 1 ; i <= n ; ++ i)
	{
		cin >> a[i].first >> a[i].second;
		temp += a[i].first;
		cz[i] = temp; 
	}
	
	long long mid;
	mid = temp / 2 + 1;
	int ii;
	
	for(int i = 1 ; i <= n ; ++ i)
	{
		if(mid <= cz[i])
		{
			ii = i;
			break;
		}
	}
	
	for(int i = 1 ; i < ii ; ++ i)
	{
		//处理不同的情况 
		if(a[i].first > a[n + 1 - i].first)
		{
			int ks = 0;
			while(a[i].first != 0)
			{
				if(a[i].second == a[n + 1 - i - ks].second)
				{
					if(a[i].first <= a[n + 1 - i - ks].first)
					{
						a[n + 1 - i - ks].first -= a[i].first;
						a[i].first = 0;
					}
					if(a[i].first > a[n + 1 - i - ks].first)
					{
						a[i].first -= a[n + 1 - i - ks].first;
						a[n + 1 - i - ks].first = 0;
					}
					ks ++;
					continue;
					//相等的情况不用累加 
				}
				if(a[i].first > a[n + 1 - i - ks].first)
				{
					a[i].first -= a[n + 1 - i - ks].first;
					ans += a[n + 1 - i - ks].first;
					a[n + 1 - i - ks].first = 0;
				}
				if(a[i].first <= a[n + 1 - i - ks].first)
				{
					a[n + 1 - i - ks].first -= a[i].first;
					ans += a[i].first;
					a[i].first = 0;
				}
				ks ++;
			}
		}
		if(a[i].second != a[n + 1 - i].second)
		{
			ans += a[i].first;
			a[n + 1 - i].first -= a[i].first;
			a[i].first = 0;
		}
		if(a[i].second == a[n + 1 - i].second)
		{
			a[n + 1 - i].first -= a[i].first;
			a[i].first = 0;
		}
	}
	
	printf("%lld" , ans);
	
	return 0;
}
//时山代码 
