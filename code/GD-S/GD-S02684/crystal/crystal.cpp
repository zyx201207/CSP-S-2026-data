#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int z = n / 2;
	int sum = 0;
	for(int i=1;i<=m;i++)
	{
		if (a[i] <= a[z])
		{
			ans = a[z] - a[i];
			if (m < ans)
			{
				break;
			}
			a[i] += ans;
			m -= ans; 
			sum++;
		} 
	}
	cout << sum;
	return 0;
} 

