#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long c , n , m , d , q;
long long k , a , t;
long long s , e;
long long ans , ans1;
long long w[N];
long long at[25][25005];
bool ar[25][25005];

void dfs(long long nr , long long ns)
{
	if (ns == e)
	{
		ans1 += at[e][nr];
		ans = min(ans , ans1);
		return;
	}
	for (long long i = 1 ; i <= m ; i ++)
	{
		if (!ar[nr][i] && at[nr][i] != -1)
		{
			ar[nr][i] = true;
			dfs(nr , i);
			ar[nr][i] = false;
		}
	}
	for (long long i = 1 ; i <= n ; i ++)
	{
		if (at[i][ns] != -1 && i != nr)
		{
			ar[nr][ns] = true;
			ans1 += at[nr][ns] + ar[i][ns];
			dfs(i , ns);
			ar[nr][ns] = false;
			ans1 -= at[nr][ns] + ar[i][ns];
		}
	}
	return;
}

int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(at , -1 , sizeof(at));
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1 ; i <= m ; i ++)
	{
		cin >> w[i];
	}
	for (long long i = 1 ; i <= n ; i ++)
	{
		cin >> k;
		for (long long j = 1 ; j <= k ; j ++)
		{
			cin >> a >> t;
			at[i][a] = t;
		}
	}
	while (q --)
	{
		cin >> s >> e;
		ans = N;
		for (long long i = 1 ; i <= n ; i ++)
		{
			if (at[s][i] != -1)
			{
				ans1 = w[s] + at[i][s] + w[e];
				ar[i][s] = true;
				memset(ar , false , sizeof(ar));
				dfs(s , i);
			}
		}
		cout << ans << endl;
	}

	return 0;
}
