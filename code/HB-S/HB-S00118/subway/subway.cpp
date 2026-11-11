#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+5;
int c, n, m, d, q;
int time_[N];
int dis[N][N];
void floyd()
{
	for(int k = 1; k<=m; k++)
	{
		for(int i = 1; i<=m; i++)
		{
			for(int j = 1; j<=m; j++)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
		}
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr), cout.tie(nullptr);
	memset(dis, 0x3f, sizeof(dis));
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i = 1; i<=m; i++)
	{
		scanf("%lld", &time_[i]);
		dis[i][i] = 0;
	}
	for(int i = 1; i<=n; i++)
	{
		int num;
		scanf("%lld", &num);
		int sta[num+1], t[num+1];
		for(int j = 1; j<=num; j++)
		{
			scanf("%lld%lld", &sta[j], &t[j]);
			if(j==1)
				continue;
			dis[sta[j]][sta[j-1]] = t[j]+t[j-1];
			dis[sta[j-1]][sta[j]] = t[j]+t[j-1];
		}
		dis[sta[num]][sta[1]] = t[num]+t[1];
		dis[sta[1]][sta[num]] = t[num]+t[1];
	}
	floyd();
	while(q--)
	{
		int s, e;
		scanf("%lld%lld", &s, &e);
		printf("%lld\n", time_[s]+dis[s][e]+time_[e]);
	}
	return 0;
}
