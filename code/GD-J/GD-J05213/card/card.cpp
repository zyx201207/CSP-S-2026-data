#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],num[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	while(n--)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int s = 1;s <= m;s++)
			{
				b[s] = 0;
			}
			for(int j = i;j <= n;j++)
			{
				b[a[j]]++;
				if(b[a[j]] > 1)
				{
					for(int k = 1;k <= m;k++)
					{
						b[k] = 0;
					}
				}
				b[a[j]] = 1;
			}
		    for(int x = 1;x <= m;x++)
			{
				if(b[x] == 1)
				{
					num[x]++;
				}
		    }
		}
	
	}
	for(int i = 1;i <= m;i++)
	{
		cout << num[i] << " ";
    }
	return 0;
}
