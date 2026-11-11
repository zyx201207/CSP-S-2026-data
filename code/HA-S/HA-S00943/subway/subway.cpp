#include<bits/stdc++.h>
#define ll long long 

using namespace std;
ll c, n, m, d, p, tot;
ll w[500010], dis[500010], vis[500010], ans[100010];
ll head[505010], to[505010], nxt[505010], val[505010];
struct op{
	ll nu, va;
};
struct po{
	ll u, v, nu;
}e[100010];
bool operator<(op A, op B)
{
	return A.va > B.va;
}
bool cmp(po A, po B)
{
	return A.u > B.u;
}
void add(ll u, ll v, ll w)
{
	to[++tot] = v;
	nxt[tot] = head[u];
	val[tot] = w;
	head[u] = tot;
}
void dj(int s)
{
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[s] = 0;
	vis[s] = 1;
	priority_queue<op> q;
	q.push({s, 0});
	while(!q.empty())
	{
		ll u = q.top().nu;
		q.pop();
		vis[u] = 1;
		for(int i = head[u]; i; i = nxt[i])
		{
			ll v = to[i], k = dis[u] + val[i];
			if(!vis[v] && dis[v] > k)
			{
				dis[v] = k;
				q.push({v, dis[v]});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;

	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		ll k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			ll a, t;
			cin >> a >> t;
			add(i, a + n, t);
			add(a + n, i, t);
		}
	}
	for(int i = 1; i <= p; i++)
	{
		cin >> e[i].u >> e[i].v;
		e[i].nu = i;
	}
	sort(e + 1, e + p + 1, cmp);
	ll be = 0;
	for(int i = 1; i <= p; i++)
	{
		ll x = e[i].u, y = e[i].v, z = e[i].nu;
		if(x != be)
		{
			dj(x + n);
			be = x;
		}
		ll ss = dis[y+n] + w[x] + w[y];
		ans[z] = ss;
	}
	for(int i = 1; i <= p; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}
