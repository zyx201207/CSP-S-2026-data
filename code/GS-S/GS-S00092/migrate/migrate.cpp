#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , t;
	cin >> c >> t;
	while(t--)
	{
		int n , d , pos = 0;
		cin >> n >> d;
		int x[n + 1] , b[n + 1];
		for (int i = 1;i <= n;i++)
			cin >> x[i];
		for (int i = 1;i <=n;i++)
		{
			if (x[i] - x[i - 1] <= d)
			{
				b[i] = abs(x[i] - x[i - 1]);
				pos++;
			}
			else
				break;
		}
		int ans = 0 , tag = -1 , cnt[pos + 1] , pos2 = 1;
		memset(cnt , 0 , n + 1);
		for (int i = 1;i <= pos;i++)
		{
			if (b[i] != tag)
			{
				tag = b[i];
				cnt[pos2] = 0;
				pos2++;
			}
			else
			{
				cnt[pos2]++;
			}
		}
		for (int i = 1;i <= pos2;i++)
		{
			if (cnt[i] == 4)
				ans++;
		}
		cout << ans << "\n"; 
	}
	return 0;
}
