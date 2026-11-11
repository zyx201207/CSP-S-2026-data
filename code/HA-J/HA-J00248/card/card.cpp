#include <bits/stdc++.h>
using namespace std;
long long n,m;
int l[10005];
int re = 0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	long long a[n+1],b[m+1];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int h = 1;h <= m;h++)
	{
		int i = 1;
		for(int p = 1;p <= n-h+1;p++)
		{
			l[i] = a[p];
			re = 0;
			for(int f = 1;f < i;f++)
			{
				if(l[f] == l[i])
				{
					re = f;
					break;
				}	
			}
			if(re)
			{
				l[re] = l[i];
				for(int s = re + 1;s <= i;s++)
				{
					l[s] = 0;
				}
			}
		}
		int u = 1;
		while(l[u] != 0)
		{
			b[l[u]]++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
