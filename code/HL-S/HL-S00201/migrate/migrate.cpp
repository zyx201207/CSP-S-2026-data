#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		int n;
		long long d;
		cin >> n >> d;
		vector<long long> p(n);
		for(int i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		long long ans = 0;
		for(int i = 0; i < n; i++)
		{
			vector<int> dis(n, 1e8);
			vector<int> cnt(n, 0);
			dis[i] = 0;
			for(int j = i; j < n; j++)
			{
				for(int k = j + 1; p[k] - p[j] <= d; k++)
				{
					if(dis[k] > dis[j] + 1) 
					{
						dis[k] = dis[j] + 1;
						cnt[k] = 1;
					}
					else if(dis[k] == dis[j] + 1) cnt[k]++;
				}
				if(cnt[j] == 2) ans++; 
			}
		}
		cout << ans << endl;
	} 

	return 0;
}

