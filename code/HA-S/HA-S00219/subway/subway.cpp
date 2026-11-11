#include <bits/stdc++.h>
using namespace std;
long long w[1000005],t[500005][500005],a[500005][500005],b[500005][500005],x[505];
int main()
{
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	int y = 1;
	while(n--)
	{
		cin >> x[y];
		for(int i = 1;i <= x[y];i++)
		{
			cin >> a[n][i] >> t[n][i];
		}
		y++;
	}
	y = 1;
	while(q--)
	{
		for(int i = 1;i <= 2;i++)
		{
			cin >> b[i];
		}
	}
	bool c = 0;
	int l1,r1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= x[i])
		{
			if(a[i][j] == b[1])
			{
				l1 = i;
				r1 = j;
				c = 1;
				break;
			}
		}
		if(c)
		{
			break;
		}
	}
	int l2,r2;
	c = 0
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= x[i])
		{
			if(a[i][j] == b[2])
			{
				l2 = i;
				r2 = j;
				c = 1;
				break;
			}
		}
		if(c)
		{
			break;
		}
	}
	int l3 = a[l1][r1],r3 = a[l2][r2];
	sum += w[l3] + w[r3];
	int u = 1;
	if(l1 == l2)
	{
		sum += (r2 - r1) * 2;
	}
	else
	{
		for(int i = r1;i <= x[y];i++)
		{
			for(;u <= r2;u++)
			{
				if(a[l1][i] == a[l2][u])
				{
					sum += (i - r1 + r2 - u) * 2;
				}
			}
		}
	}
	cout << sum;
	return 0;
}