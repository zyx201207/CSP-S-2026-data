#include <bits/stdc++.h>
using namespace std;
int a[500009];int z[500005];
int main()
{
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n-i;j++)
		{
			cin >> a[j];
			for(int q =1;q<=j-1;q++)
			{
				if(a[q]==a[j])
				for(int w = q;w <= j;w++)
				{
					a[q] = a[q + j - 1];
				}
			}
		}
		int sum = 0;
		for(int q = 1;q<=m;q++)
		{
			for(int w = 1;w<=n;w++)
			{
				if(q==a[w])sum++;
			}
			z[q]=sum;
		}
	}
	int e = 0;
	for(int i = 1;i <= m;i++)
	{
		for(int j = i;j <= 100;j+=m)
		{
			e+=z[i];
		}
		cout << e << " ";
	}
	return 0;
}
