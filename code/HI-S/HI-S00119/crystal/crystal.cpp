#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,a[500005],v[5000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort (a+1,a+n+1);
	if (n <= 5000)
	{
		int sum = 0,cnt = 0;
		for (int j = n;j >= 2;j--)
		{
			int z = 2,w = a[j];
			v[1] = a[j];
			v[2] = a[j]-a[j-1];
			for (int k = j-2;k >= 1;k--)
			{
				z++;
				sum = z-2;
				v[z] = v[1]-a[k]+v[z-1];
				if (v[z-2] <= m)
				{
					cnt = max(sum,cnt);
				}
			}
		}
		cout << cnt;
	}
	else if (a[2] - a[1] == 1)
	{
		int pre = 1;
		while (m > 0)
		{
			m -= pre;
			pre++;
		}
		cout << pre;
	}
	else
	{
		if (n % 2 == 1)
		{
			cout << n/2+1;
		}
		else
		{
			cout << n/2;
		}
	}
	return 0;
}

