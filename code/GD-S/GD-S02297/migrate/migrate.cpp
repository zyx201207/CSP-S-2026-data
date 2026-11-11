#include <bits/stdc++.h>
using namespace std;
int dp[200010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		cin >> n >> d;
		int a[n+3];
		for (int i=1; i<= n;i++)
		{
			cin >> a[i];
		}
		for (int i=1;i <= d;i++)
		{
			dp[i]==1;
		}
		if (a[1]-a[2] >= d)
		{
			cout << 0;
			return 0;
		}
		else 
		{
			if (d < 2*(a[2]-a[1]))
			{
				cout << 1;
				return 0;
			}
			else
			{
				cout << (n+2)/3;
			}
		}
	}
	return 0;
}
