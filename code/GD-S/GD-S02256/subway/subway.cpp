#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int b[500010] , t[500010];
vector<int> col[500010];
struct node
{
	int point , time;
};
vector<node> edge[500010];
int dis[510][510];
signed main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	int c , n , m , d , q;
	scanf("%lld%lld%lld%lld%lld" , &c , &n , &m , &d , &q);
	for(int i = 1 ; i <= m ; i++)scanf("%lld" , &a[i]);
	for(int i = 1 ; i <= n ; i++)
	{
		int k;
		scanf("%lld" , &k);
		for(int j = 1 ; j <= k ; j++)
		{
			int a , t;
			scanf("%lld%lld" , &a , &t);
			edge[a].push_back({i , t});
		}
	}
	memset(dis , 0x3f , sizeof dis);
	for(int i = 1 ; i <= m ; i++)
	{
		for(auto t1 : edge[i])
		{
			for(auto t2 : edge[i])
			{
				if(t1.point == t2.point)continue;
				dis[t1.point][t2.point] = min(dis[t1.point][t2.point] , t1.time + t2.time);
			}
		}
	}
	for(int i = 1 ; i <= n ; i++)dis[i][i] = 0;
	for(int k = 1 ; k <= n ; k++)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int s , t;
			scanf("%lld%lld" , &s , &t);
		int res = a[s] + a[t] , ans = 1e18;
		for(auto t1: edge[s])
		{
			for(auto t2 : edge[t])
			{
				ans = min(ans , dis[t1.point][t2.point] + t1.time + t2.time);
			}
		}
		printf("%lld\n" , ans + res);
	}
	return 0;
}
