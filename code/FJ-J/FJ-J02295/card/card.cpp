#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
bool ccc[300005];
int d[300005];
int answer[300003];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >>m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int c=0;
	for(int i = 1; i <= n; i++)
	{
		c = 0;
		for(int j = 1; j <= m; j++)
		{
			b[i] = 0;
			ccc[i] = 0;
			d[i] = 0;
		}
		for(int j = i; j <= n; j++)
		{
			if(ccc[a[j]] == 1)
			{
				int ans = 0;
				for(int z = d[a[j]]; z<=c; z++)
				{
					d[b[z]] = 0;
					ccc[b[z]] = 0;
					ans++;
					b[z] = 0;
				}
				c -= ans;
			}
			c++;
			d[a[j]] = c;
			ccc[a[j]] = 1;
			b[c] = a[j];
		}
		for(int j = 1; j <= c; j++)
		{
			answer[b[j]]++;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}
