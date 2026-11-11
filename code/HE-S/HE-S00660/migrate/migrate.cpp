#include <iostream>
#define ll long long
using namespace std;
const int N = 2000005;
ll c, T, n, a[N], d, tot;
pair<ll, ll> f[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> d;
		tot = 0;
		for(int i = 1 ; i <= n ; i++)
			cin >> a[i];
		for(int k = 1 ; k < n ; k++)
		{
			int ans = 0;
			f[k] = {0, 1};
			for(int i = k + 1 ; i <= n ; i++)
			{
				f[i].first = 9e18;
				f[i].second = 0;
				int j = i - 1;
				if(a[i] - a[j] > d)
					break;
				while(a[i] - a[j] <= d && j >= k)
				{
					if(f[j].first + 1 < f[i].first)
					{
						f[i].first = f[j].first + 1;
						f[i].second = 1;
					}
					else if(f[j].first + 1 == f[i].first)
					{
						f[i].second++;
					}
					j--;
				}
				//cout << f[i].first << " " << f[i].second << "\n";
				if(f[i].second == 2)
					ans++;
			}
			tot += ans;
			//cout << "\n";
		}
		cout << tot << "\n";
	}
	return 0;
}
