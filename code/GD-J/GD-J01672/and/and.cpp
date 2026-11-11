#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int a[N] , n , m , a1[N];
int ans1;

int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	
	cin >> n >> m;
	if(m == 1 || m == 2 || m == n - 1)
		ans1 = -INF;
	
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i];
		if(m == 1)
		{
			ans1 = max(ans1 , a[i]);
		}
		else if(m == n)
		{
			if(i == 1)
				ans1 = a[i];
			else
				ans1 &= a[i];
		}
	}
	if(m == 2)
	{
		for(int i = 1; i<=n; i++)
		{
			for(int j = 1; j<=n; j++)
			{
				if(i != j)
				{
					ans1 = max(ans1 , a[i] & a[j]);
				}
			}
		}
	}
	else if(m == n - 1)
	{
		int tmp = 0;
		for(int i = 1; i<=n; i++)
		{
			if(i == 1)
				tmp = a[2];
			else
				tmp = a[1];
			for(int j = 1; j<=n; j++)
			{
				if(j != i)
				{
					tmp = tmp & a[j];
				}
			}
			ans1 = max(tmp , ans1);
		}
	}
	if(m == 1 || m == 2 || m == n || m == n - 1)
	{
		cout << ans1;
		return 0;
	}
	ans1 = INF;
	for(int i = 1; i<=n; i++)
	{
		ans1 = min(ans1 , a[i]);
	}
	cout << ans1;
	
	return 0;
}
