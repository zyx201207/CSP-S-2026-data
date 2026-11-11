#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[2000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	long long g;
	while (t--)
	{
		cin >> n >> d;
		for (int i=1; i<=n; i++)
		{
			cin >> a[i]; 
		}
		g=a[2]-a[1];
		//cout << g << '\n'; 
		long long l=-1e18, r=1e18, mid=0;
		while (l<=r)
		{
			//cout << mid << ' ';
			if ((mid+1)*g<=d)
			{
				l=mid+1;
			}
			else if (mid*g>d)
			{
				r=mid-1;
			}
			else
			{
				break;
			}
			mid=(l+r)/2;
		}
		long long ans=n-2*mid+1;
		if (mid<2 || ans<0)
		{
			cout << 0 << '\n';
		}
		else
		{
			cout << ans << '\n';
		}
	}
	return 0;
}
