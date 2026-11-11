#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long c, t, n, d, u[2000005], ans;

struct nd{
	long long v, m;
};

int bfs(ll x, ll y)
{
	ll mn = 2000005, res = 0;
	queue<nd> q;
	q.push({x, 1});
	while(!q.empty())
	{
		ll a = q.front().v, b = q.front().m;
		if(a == y)
		{
			if(b < mn)
			{
				mn = b;
				res = 0;
			}
			else 
			{
				res++;
			}
		}
		q.pop();
		for(ll i = a + 1; i <= n && u[i] - u[a] <= d; i++)
		{
			q.push({i, b + 1});
		}
	}
	return (res == 2);
}


int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &c, &t);
	while(t--)
	{
		ans = 0;
		//~ cout << 1 << endl;
		scanf("%lld %lld", &n, &d);
		for(ll i = 1; i <= n; i++)
		{
			scanf("%lld", &u[i]);
		}
		for(ll i = 1; i <= n; i++)
		{
			for(ll k = 1; k <= n; k++)
			{
				if(k == i)continue;
				
				ans += bfs(i, k);
			}
			
		}
		printf("%lld\n", ans);
	}
	return 0;
}

