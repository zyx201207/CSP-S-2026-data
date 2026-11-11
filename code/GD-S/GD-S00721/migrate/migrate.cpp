#include<bits/stdc++.h>
using namespace std;
const int N = 2000010;
struct node{
	long long u,w;
	bool operator > (const node &x) const{
		return w > x.w;
	}
};
int n;
long long d;
long long a[N];
vector<int> g[N];
long long dis[N],vis[N],cnt[N];
void dijkstra(int st)
{
	for(int i=1;i<=n;i++) dis[i] = 1e18,vis[i] = 0,cnt[i] = 0;
	priority_queue<node,vector<node>,greater<node> > pq;
	pq.push({st,0});
	dis[st] = 0,cnt[st] = 1;
	int ct = 0;
	while(pq.size())
	{
		ct++;
	    node t = pq.top();
		pq.pop();
		int u = t.u;
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto v:g[u])
		{
			if(dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				pq.push({v,dis[v]});
			}
			else if(dis[v] == dis[u] + 1)
			{
				cnt[v] += cnt[u];
			}
		}
	}
}
void solve()
{
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(abs(a[i] - a[j]) <= d)
			{
				g[i].push_back(j);
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
		for(int j=i+1;j<=n;j++)
		{
			if(cnt[j] == 2)
			{
				ans++;
			}
		}
	}
	cout << ans << "\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[i];
		if(n <= 5000) solve();
		else cout << 0 << "\n";
	}
	return 0;
}

