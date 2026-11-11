#include <bits/stdc++.h>
using namespace std;
const int N = 1e+4;
long long c,t,n,d;
long long x[N];
long long ans = 0;

int main()
{
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		ans = 0;
		for (long long i = 1; i <= n ; i++)
		{
			cin >> x[i];
		}
		
		for (long long u = 1 ; u <= n -3 +1 ; u++)
		{
			long long temp =x[u +3];
			long long cnt = 0;
			for (long long v = u + 3 - 1 ; v > 0 ; v--)
			{
				if (x[v] + d >= temp)
				{
					cnt++;
				}
			}
			if (cnt == 2) ans++;
		}
		cout << ans << endl;
	}
	
	return 0;
}
