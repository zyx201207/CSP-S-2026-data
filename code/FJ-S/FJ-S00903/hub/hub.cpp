#include <bits/stdc++.h>

using namespace std;
long long u[2000005];
long long v[2000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c;
	cin >> c;
	long long t;
	cin >> t;
	int x = 1;
	while(t--)
	{
		long long n , k;
		cin >> n >> k;
		for(long long i = 1;i <= n;i ++)
		{
			cin >> u[i] >> v[i];
		}
		long long ans = 1e9;
		if(x%2!=0)
		{
			for(long long i = 1;i <= n;i ++)
			{
				ans = min(ans,u[i]);
			}
		}
		else
		{
			for(long long i = 1;i <= n;i ++)
			{

				ans = min(ans,v[i]-1);
			}
		}
		cout << ans << "\n";
		x ++;
	}
	return 0;
}