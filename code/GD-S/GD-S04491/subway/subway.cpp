#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int N = 5e5 + 505;
const ll inf = 1e18;

struct node
{
	int v,w;
};
vector<node> e[N];
ll c,n,m,xz,qq;
ll a[N],d[N];
bool vis[N];

void dij(int s)
{
	for (int i = 1;i <= m+n;i++)vis[i]=0,d[i]=inf;
	d[s]=0;
	priority_queue<pair<int,int> > q;
	q.push({0,s});
	while (q.size())
	{
		ll u = q.top().second;q.pop();
		if (vis[u])continue;
		vis[u]=1;
		for (auto ed:e[u])
		{
			ll v = ed.v,w = ed.w;
			if (d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push({-d[v],v});
			}
		}
	}
}
void gc()
{
	cin>>c>>m>>n>>xz>>qq;
	for (int i = 1;i <= n;i++)cin>>a[i];
	for (int i = 1;i <= m;i++)
	{
		ll k;
		cin>>k;
		for (int j = 1;j <= k;j++)
		{
			ll v,w;
			cin >> v >> w;
			e[i+n].push_back({v,w});
			e[v].push_back({i+n,w});
		}
	}
	for (int i = 1;i <= qq;i++)
	{
		ll u,v;
		cin >> u >> v;
		dij(u);
		cout<<d[v]+a[u]+a[v]<<"\n";
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	gc();
	return 0;
}
