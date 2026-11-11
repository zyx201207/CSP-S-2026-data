#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
long long c, t, n, d, a[1000005] = {}, pos[1000005] = {}, dis[1000005] = {}, cnt = 0, len = 0;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(i > 1 && a[i]-a[i-1] > d && !cnt) cnt = i-1;
		}
		n = cnt;
		long long ans = 0;
		for(int i = 1; i <= n; i++)
		{
			len = 0;
			memset(pos, 0, sizeof(pos));
			memset(dis, 0, sizeof(dis));
			int flag = 0;
			for(int j = i+1; j <= n; j++)
			{
				long long p = a[j]-a[j-1];
				if(dis[len+1]+p <= d)
				{
					dis[len+1] += p;
				}
				else
				{
					pos[++len] = j-1, dis[len+1] = a[j]-a[j-1];
					if(len > 1 && dis[len]+a[pos[len-1]]-a[pos[len-1]-1] <= d && !flag)
					{
						if(pos[len-1] < 2 || dis[len]+a[pos[len-1]]-a[pos[len-1]-2] > d)
							ans += n-pos[len-1], flag = 1;
						else flag = 2;
					}
				}
				if(len > 0 && dis[len+1]+a[pos[len]]-a[pos[len]-1] <= d && (pos[len] < 2 || dis[len+1]+a[pos[len]]-a[pos[len]-2] > d))
				{
					if(flag == 0) ans++;
					else if(flag == 1) ans--; 
				}
			} 
		}
		cout << ans << "\n";
	} 
	return 0;
}
