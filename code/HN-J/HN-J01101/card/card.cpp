#include <bits/stdc++.h>
using namespace std;
int n , m , zhang;
int a[500005];
int f[300005];
int zhuo[500005];
int ans[300005];
int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int t = n;
	while(t --)
	{
		memset(f , 0 , sizeof(f));
		memset(zhuo , 0 , sizeof(zhuo));
		zhang = 0;
		for(int i = n - t; i <= n; i++)
		{
			if(f[a[i]] == 1)
			{
				while(zhuo[zhang] != a[i])
				{
					f[zhuo[zhang]] --;
					zhuo[zhang] = 0;
					zhang --;
				}
			}
			else
			{
				f[a[i]] ++;
				zhang ++;
				zhuo[zhang] = a[i];
			}
		}
		for(int i = 1; i <= zhang; i++)
		{
			ans[zhuo[i]] ++;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
