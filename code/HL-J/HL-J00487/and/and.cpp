#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,lax = 0;
	cin >> n >> m;
	long long a[n + 5];
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		if(m % 2 == 0&&a[i] % 2 == 0 && a[i] > lax)
		{
			lax = a[i];
		}
		else if(m % 2 != 0 && a[i] > lax)
		{
			lax = a[i];
		}
	}
	cout << lax;
	return 0;
}
