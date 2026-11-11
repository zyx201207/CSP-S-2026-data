#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005],n,m,sum,l,x[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	
	l = 1;
	while(l <= n)
	{
		sum = l;
		for(int i = l;i < n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				if(a[i] == b[j])
				{
					i = j;
					sum = j;
				}
			}
		}
		for(int r = sum;r <= n;r++)
		{
			for(int k = 1;k <= m;k++)
			{
				if(a[r] == k)
				{
					x[k]++;
				}
			}
		}
		l++;
	}
	for(int i = 1;i <= m;i++)
	{
		cout << x[i] << " ";
	}
	return 0;
}