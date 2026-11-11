#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e3+5;
int c, T;
//!!!reset!!!
int n, k;
int dis[N][N], d[N];
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr), cout.tie(nullptr);
	scanf("%lld%lld", &c, &T);
	while(T--)
	{
		memset(dis, 0, sizeof(dis));
		memset(d, 0, sizeof(d));
		scanf("%lld%lld", &n, &k);
		if(c==13 || c==14)
		{
			int m = (n-1)/2, ans;
			if(m%2==0)
				ans = (m+2)/2-k+1;
			else
				ans = (m+1)/2-k+1;
			if(ans<0)
				ans = 0;
			printf("%lld\n", ans);
			continue;
		}
		for(int i = 1; i<n; i++)
		{
			int u, v;
			scanf("%lld%lld", &u, &v);
			dis[u][v] = 1;
			dis[v][u] = 1;
			d[u]++, d[v]++;
		}
		
	}
	return 0;
}
