#include <bits/stdc++.h>
using namespace std;
long long C,T,n,d,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> C >> T;
	while (T--)
	{
		long long cnt = 0;
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> x[i];
			if ((d < (x[i + 1] - x[i]) * 2) || n < 4)
			{
				cnt = 0;
			}
			else
			{
				cnt = n - 3;
			}
		}
		cout << cnt << endl;
	}
}
