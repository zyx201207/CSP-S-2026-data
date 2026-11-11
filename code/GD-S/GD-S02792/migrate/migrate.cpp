#include <bits/stdc++.h>
using namespace std;

long long x[2000005];
vector<long long> v[2000005];
long long dis[2000005];
long long cnt[2000005];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	while(t--)
	{
		long long n, d;
		cin >> n >> d;
		for(long long i = 1; i <= n; i++) cin >> x[i];
		for(long long i = 1; i <= n; i++)
			for(long long j = i + 1; j <= n; j++)
				if(x[j] - x[i] <= d) v[i].push_back(j), v[j].push_back(i);
		long long sum = 0;
		for(long long i = 1; i <= n; i++)
		{
			queue<long long> q;
			q.push(i);
			long long ans = 0;
			while(!q.empty())
			{
				long long x = q.front();
				q.pop();
				for(long long j = 0; j < v[x].size(); j++)
				{
					long long y = v[x][j];
					if(!dis[y] && y != i)
					{
						dis[y] = dis[x] + 1;
						cnt[y] = 1;
						q.push(y);
					}
					else if(dis[y] == dis[x] + 1) cnt[y]++;
				}
			}
			for(long long j = i + 1; j <= n; j++) if(cnt[j] == 2) ans++;
			for(long long j = 1; j <= n; j++) {dis[j] = 0, cnt[j] = 0;}
			sum += ans;
		}
		cout << sum << "\n";
		for(long long i = 1; i <= n; i++) v[i].clear();
	}
	return 0;
}
