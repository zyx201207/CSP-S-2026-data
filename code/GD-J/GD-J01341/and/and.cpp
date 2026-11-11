#include<bits/stdc++.h>
using namespace std;
long long n , m , k , sum , a[200010];
long long dp[200010];
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	scanf("%lld" , &n);
	scanf("%lld" , &m);
	for(int i = 1; i <= n; i++) scanf("%lld" , &a[i]);
	if(m == 1)
	{
		cout << a[n];
		return 0;
	}
	if(m == 2)
	{
		for(int i = 1; i <= n - 1; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				k = max(k , a[i] & a[j]);
			}
		}
		cout << k;
		return 0;
	}
	sort(a + 1 , a + 1 + n);
	for(int i = n; i >= 1; i--)
	{
		m--;
		if(m == 0) break;
		k = a[i] & a[i - 1];
		
	}
	cout << k;
	return 0;
} 
