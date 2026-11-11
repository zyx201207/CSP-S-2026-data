#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, T, n, k, u, v;
ll cnt, head[1000005], f[1000005], dis[1000005], ans;
bool b[1000005], bb[1000005];
queue<ll>q;
struct Edge
{
	ll v, next;
} e[2000005];
void add(ll u, ll v)
{
	cnt++;
	e[cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}
ll findd(ll k)
{
	if(f[k] != k)f[k] = findd(f[k]);
	return f[k];
}
void dfs(ll t, ll s)
{
	if(s > k)
	{
		ll cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			f[i] = i;
//			cout<<b[i]<<' ';
		}
//		cout<<endl;
		for(int i = 1; i <= n; i++)
		{
			for(int j = head[u]; j; j = e[j].next)
			{
				if(b[i] && b[e[j].v]&&findd(i)!=findd(e[j].v)){
					f[findd(i)] = findd(e[j].v);
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			if(b[i] && i == findd(i))cnt++;
		}
//		cout<<cnt<<endl;
		if(cnt <= 2)
		{
			for(int i = 1; i <= n; i++)
			{
				dis[i] = 1e17;
				if(b[i])
				{
					dis[i] = 0;
					q.push(i);
				}
			}
			while(!q.empty())
			{
				ll u = q.front();
				q.pop();
				for(int i = head[u]; i; i = e[i].next)
				{
					ll v = e[i].v;
					if(dis[v] > dis[u] + 1)
					{
						dis[v] = dis[u] + 1;
						q.push(v);
					}
				}
			}
			ll maxx = -1e17;
			for(int i = 1; i <= n; i++)
			{
				maxx = max(maxx, dis[i]);
			}
			ans = min(ans, maxx);
		}
		return;
	}
	for(int i = t; i <= n - (k - s + 1) + 1;i++)
	{
		b[i] = 1;
		dfs(i + 1, s + 1);
		b[i] = 0;
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
		{
			head[i] = 0;
		}
		cnt = 0;
		for(int i = 1; i < n; i++)
		{
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		ans=1e17;
		dfs(1, 1);
		cout<<ans<<'\n';
	}
	return 0;
}
//0 2
//5 2
//1 2
//2 3
//3 4
//4 5
//10 3
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//3 8
//7 9
//9 10
