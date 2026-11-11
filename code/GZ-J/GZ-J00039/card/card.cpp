#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],sum[100005],b[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int j = 1; j <= n; j++)
	{
		for(int i = j; i <= n; i++)
		{
			for(int x = 1; x <= n ; x++)
			{
				if(a[i] == a[i + 1])
				{
					b[i] = 1;
					b[i + 1] = 1;
				}
			}
			if(a[i] == i && b[i] != 1)
			{
				sum[i]++;
			}
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << sum[i] << " ";
	}
	return 0;
}
