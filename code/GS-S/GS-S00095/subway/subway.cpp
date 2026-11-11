#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,a[100000],b[1000000][1000000],time[1000000][1000000],x,y[1000000][2],w,num;
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		long long z;
		cin >> z;
		for (int j = 0; j < z; j++)
		{
			cin >> b[i][j];
			cin >> time[i][j];
		}
		for (int j = 0; j < q; j++)
		{
			cin >> y[j][0];
			cin >> y [j][1];
		}
	}
	for (int i = 0; i < q; i++)
	{
		x = y[i][0];
		num = 0;
		num += a[x];
		for (int j = 0; j < d; j++)
		{
			for (int k = 0; k < d; k++)
			{
				if (b[j][k] == x)
				{
					num += time[i][j];
				}
			}
		}
		while(x < y[i][1])
		{
			for (int j = 0; j < d; j++)
			{
				for (int k = 0; k < d; k++)
				{
					if (b[j][k] == x)
					{
						w = k + 1;
						while(b[j][w] < y[i][1])
						{
							x++;
							w++; 
						}
						break;
					}
				}
			}
			num += a[x];
			for (int j = 0; j < d; j++)
			{
				for (int k = 0; k < d; k++)
				{
					if (b[j][k] == x)
					{
						num += time[i][j];
					}
				}
			}
		}
		cout << num;
	}	
	return 0;	
}
