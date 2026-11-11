#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[500005] = {}, b[300005] = {}, c[500005] = {}, v[500005] = {};
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=n; j++)
		{
			if(!(b[a[j]]))
			{
				v[j] = a[j];
				b[a[j]] = j-i+1;
			}
			else
			{
				for(int k=b[a[j]]; k<j; k++)
				{
					v[k] = 0;
				}
				v[j] = a[j];
				b[a[j]] = j-i+1;
			}
		}
		for(int j=i; j<=n; j++)
		{
			if(v[j] != 0)
			{
				c[v[j]]++;
			}
		}
		for(int k=1; k<=n; k++)
		{
			b[k] = 0;
			v[k] = 0;
		}
	}
	for(int i=1; i<=m; i++)
	{
		cout << c[i] << ' ';
	}
	return 0;
}
