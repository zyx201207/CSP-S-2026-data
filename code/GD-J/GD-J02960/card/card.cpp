#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int a[500010] = {};
	int b[300010] = {};
	bool c[300010] = {};
	int d[500010] = {};
	for(int i = 1;i <=n;i++)
	{
		cin >> a[i];
	}
	int term = 1;
	while(term <= n)
	{
		for(int i = term;i <= n;i++)
		{
			if(c[a[i]] == 0)
			{
				d[i] = a[i];
				c[a[i]] = 1;
			}
			else
			{
				d[i] = a[i];
				for(int j = term;j < i;j++)
				{
					bool flag = 0;
					if(d[j] == a[i])
					{
						flag = 1;
					}
					if(flag == 1)
					{
						c[d[j]] = 0;
						d[j] = -1;
					}
				}
				c[a[i]] = 1;
			}
		}
		for(int i = term;i <= n;i++)
		{
			if(d[i] == -1)
			{
				continue;
			}
			b[d[i]]++;
		}
		d[500010] = {};
		c[300010] = {};
		term++; 
	}
	for(int i = 1;i <= m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
