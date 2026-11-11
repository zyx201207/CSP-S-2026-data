#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[1000005],c[1000005],ans;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	while(m--)
	{
		ans++;
		for(int i = 1; i <= n; i++)
		{
			b[i] = 0;
		}
		int cnt = 1; 
		for(int i = ans; i <= n; i++)
		{
			b[cnt] = a[i];
			for(int j = 1; j <= cnt-1; j++)
			{
				if(a[j] == b[cnt])
				{
					for(int z = j; z <= cnt-1; z++)
					{
						a[z] = 0;
					}
				}
			}
			
		}
		for(int i = 1; i <= n;i++)
		{
			c[i]++;
		}
		
	}
	for(int i = 1; i <= m; i++)
	{
		cout << c[i] << " ";
	}
}
