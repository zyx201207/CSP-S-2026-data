#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int top,a[500005],n,m,z[300005],c[300005];
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int k = 1;k <= n;k++)
	{
		top = 0;
		for(int i = k;i <= n;i++)
		{
			int b = top + 1;
			bool l = 0;
			for(int j = 1;j <= top;j++)
			{
				if(z[j] == a[i])
				{
					b = j;
					l = 1;
					break;
				}
			}
			if(l)
			{
				for(int j = b;j <= top;j++)
				{
					z[j] = 0;
				}
				top = b - 1;
			}
			z[++top] = a[i];
		}
		for(int j = 1;j <= m;j++)
		{
			for(int y = 1;y <= top;y++)
			{
				if(z[y] = j)
				{
					c[j]++;
				}
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << c[i] << " ";
	}
    return 0;
}
