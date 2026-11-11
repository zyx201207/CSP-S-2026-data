
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e6+1;

int c, T;
int n;
ll d, x[N];

int main()
{
//	freopen ("migrate.in", "r", stdin);
//	freopen ("migrate.out", "w", stdout);
	
	ios::sync_with_stdio (false);
	cin.tie (nullptr), cout.tie (nullptr);
	
	cin >> c >> T;
	
	while (T--)
	{
		int mid;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 1; i <= n; i++)
			if (x[i] - x[1] <= d and x[n] - x[i] <= d)
			{
				mid = i;
				break;
			}
		if (mid == 1 or mid == n or n < 4)
		{
			cout << "0\n";
			continue;
		}
		if (mid == 2)
		{
			if (x[3] - x[1] <= d and x[4] - x[1] > d)
				cout << n-3 << '\n';
			else
				cout << "0\n";
			continue;
		}
		if (mid == n-1)
		{
			if (x[n] - x[mid-1] <= d and x[n] - x[mid-2] > d)
				cout << n-3 << '\n';
			else
				cout << "0\n";
			continue;
		}
		ll pos1 = (ll)(upper_bound (x+1, x+n+1, x[mid-1]+d) - x - 1);
		ll pos2 = (ll)(lower_bound (x+1, x+n+1, x[mid-2]+d) - x);
		ll pos3 = (ll)(lower_bound (x+1, x+n+1, x[mid+1]-d) - x);
		ll pos4 = (ll)(upper_bound (x+1, x+n+1, x[mid+2]-d) - x - 1);
		
		cout << (pos1-pos2+1) * (pos3-1) + (pos4-pos3+1) * (n-pos1) << '\n';
	}
	
	return 0;
}
