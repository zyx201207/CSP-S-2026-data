#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[2000005];
int b[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int q, n;
	cin >> q >> n;
	while(n--)
	{
		int a1, a2, cnt = 0;
		cin >> a1 >> a2;
		for (int i = 1; i <= a1; i++) cin >> a[i];
		for (int i = 1; i <= a1; i++)
		{
			for (int j = i; j <= a1; j++)
			{
				if (a[j] - a[i] < a2 * 2 && a[i] + a2 < a[j])
				{
					int r = 0;
					for (int k = i; k <= j; k++)
					{
						
						if (a[i] + a2 >= a[k] && a[j] - a2 <= a[k])
						{
							r++;
						}
					}
					if (r == 2) cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
 } 
 

