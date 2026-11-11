#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int x[MAXN], b[MAXN], c[MAXN], ans[MAXN];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
		c[i]=x[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			b[j]=x[j];
		}
		for (int j = i; j <= n; j++)
		{
			x[j]=0;
		}
		int p=1;
		for(int j = i; j <= n; j++)
		{
			bool q=0;
			
			for (int k = 1; k <= n; k++)
			{
				if(b[j]==x[k])
				{
					q=1;
				} 
				p=k;
			}
			if(q)
			{
				for (int k = p; k <= n; k++)
				{
					x[k]=0;
				}
				x[p]=b[j]; 
			}
			else
			{
				p++;
				x[p]=b[i];
			}
		}
		for (int k = 1; k <= n; k++)
		{
			if(x[k]==0)
			{
				break;
			}
			ans[x[k]]++;
		}
		for (int k = 1; k <= n; k++)
		{
			x[k]=c[k];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
