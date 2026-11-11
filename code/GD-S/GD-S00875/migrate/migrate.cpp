#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ccc,t,n;
ll d,x[2000010];
ll dis[5010][5010],vst[2000010];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> ccc >> t;
	while (t--)
	{
		scanf("%d %lld",&n,&d);
		for (int i = 1 ; i <= n ; i++)
		{
			scanf("%lld",&x[i]);
		}
		int l = 1,r = 1;
		while (l < n)
		{
			while (x[r] - x[l] <= d && r <= n)
			{
				r++;
			}
			vst[l] = r - 1;
			l++;
		}
		ll ans = 0;
		if (ccc <= 6)
		{
			int tmp;
			for (int i = 1 ; i <= n ; i++)
			{
				tmp = i;
				for (int j = i + 1 ; j <= n ; j++)
				{
					dis[i][j] = dis[i][j - 1];
					if (j > tmp)
					{
						if (tmp == vst[tmp])
						{
							dis[i][j] = n + 1;
						}
						else
						{
							tmp = vst[tmp];
							dis[i][j]++;
						}
					}
				}
			}
			for (int i = 1 ; i <= n ; i++)
			{
				for (int j = i ; j <= n ; j++)
				{
					int cnt = 0;
					for (int k = i + 1 ; k <= j - 1 ; k++)
					{
						if (dis[i][k] + dis[k][j] == dis[i][j])
						{
							cnt++;
						}
					}
					if (cnt == 2)
					{
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
