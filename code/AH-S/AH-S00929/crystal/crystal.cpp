#include <bits/stdc++.h>
using namespace std;

const long long q = 1e12 + 9;
long long n,m,a[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int ans = 1,num = 0;
	for (int j = 1;j <= 2 * q;j++)
	{
		if (m >= 1) 
		{
			ans = 1; 
			for (int i = n;i> 1;i--) 
			{
				
				if (m >= (a[n] - a[i - 1])) 
				{
					a[i] = a[n];
					m -= (a[n] - a[i - 1]);
					ans += 1; 
					num = max(num,ans); 
					if (num == n)
					{
						cout << num << " ";
						return 0;
					}
				}
				else
				{
					cout << num << " ";
					return 0;
				}
			}
		}
		else 
		{
			cout << num << " "; 
			return 0;
		}
		if (m >= 1)
		{
			a[n] += 1;
			m -= 1;
		}
	}
	return 0;
}
