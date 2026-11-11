#include <bits/stdc++.h> 
using namespace std;
int and_1(int a,int b)
{
	return (a & b);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],max = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] > max)
		{
			max = a[i];
		}
	}
    if (m == 1)
    {
    	cout << max;
	}
	else if (m == 2)
	{
		max = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (and_1(i,j) > max)
				{
					max = and_1(i,j);
				}
			}
		}
	}
	else if (m == n)
	{
		max = and_1(a[1],a[2]);
		for (int i = 3;i <= n;i++)
		{
			max = and_1(max,a[i]);
		}
	}
	else
	{
		cout << 7;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
