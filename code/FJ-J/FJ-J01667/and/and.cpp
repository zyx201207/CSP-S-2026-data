#include <bits/stdc++.h>
using namespace std;
long long n,a[10000000000000000000000000000000000000000000],m,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin >> n >> m;
	for (long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(long long i = 1;i <= n;i++)
	{
		for (long long j = 1;j < n;j++)
		{
			if(a[j] < a[j+1])
			{
				long long c = a[j];
				a[j] = a[j+1];
				a[j+1] = c;
			}
		}
	}
	ans = a[1];
	for (long long i = 2;i <= m;i++)
	{
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
