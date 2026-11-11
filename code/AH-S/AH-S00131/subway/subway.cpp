#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 5e5 + 5, MAXM = 5e2 + 5, MAXD = 2e1 + 5, MAXK = 1e3 + 5; 
ll c, n, m, d, q;
ll w[MAXN], k[MAXM];//一个站点上线路的时间；一条线路连接的个数 
ll cnt[MAXN];//每个站点连接的线路个数 
ll a[MAXM][MAXK];//一条线路连接的站点们 
ll r[MAXN][MAXD];//一个站点连接的线路们 
ll t[MAXN][MAXD];//统一上线路的时间 
ll b[MAXN];//一个站点是否被走过 
ll bs[MAXD];//一条线路内被走过的站点数量 
ll cou[MAXN];//一个站点能否走 
ll dfs(ll start, ll end, ll minn, ll time)
{
	cout << start << " " <<minn << " "<<time <<"\n";
	if(start == end)
	{
		return min(minn, time);
	}
	b[start] = 1;
	for(ll i = 1; i <= cnt[start]; i++)
	{
		//上线路
		bs[r[start][i]]++;
		if(bs[r[start][i]] < 2) 
		{
			
			for(ll j = 1; j <= k[r[start][i]]; j++)
			{
				if(b[a[r[start][i]][j]] == 0 && cou[a[r[start][i]][j]] == 0)
					minn = dfs(a[r[start][i]][j], end, minn, time + t[start][r[start][i]] + t[a[r[start][i]][j]][r[start][i]]);
			}
		}
	}
	b[start] = 0;
	cou[start] = 1;
	for(ll i = 1; i <= cnt[start]; i++)
	{
		bs[r[start][i]]--;
	}
	return minn;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i++)
	{
		scanf("%lld", &w[i]);
	}
	for(ll i = 1; i <= n; i++)
	{
		scanf("%lld", &k[i]);
		for(ll j = 1; j <= k[i]; j++)
		{
			ll x, y;
			scanf("%lld%lld", &x, &y);
			r[x][++cnt[x]] = i;
			t[x][i] = y;
			a[i][j] = x;
		}
	}
	for(ll i = 1; i <= q; i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		printf("%lld\n\n", dfs(x, y, 114514114514, w[x] + w[y]));
		for(ll j = 1; j <= m; j++) cou[j] = 0;
		for(ll j = 1; j <= n; j++) bs[j] = 0;
	}
	//printf("%lld", c);
	return 0;
}
