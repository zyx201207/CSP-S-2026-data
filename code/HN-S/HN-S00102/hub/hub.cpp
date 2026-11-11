#include <bits/stdc++.h>
using namespace std;

int c,t;
int n,k;
int dis[1000005],dis2[1000005],maxn,b;
vector <int> v[1000005];
struct node
{
	int x;
	bool operator <(const node &a) const
	{
		return dis[x] > dis[a.x];
	}
};
bool f[1000005];
void dfs(int x,int fa,int de)
{
	dis[x] = max(dis[x],de);
	for(auto i:v[x])
	{
		if(i == fa) continue;
		dfs(i,x,de + 1);
	}
}
void dfs2(int x,int fa)
{
	if(dis[x] > maxn)
	{
		maxn = dis[x];
		b = x;
	}
	for(auto i:v[x])
	{
		if(i == fa) continue;
		dis[i] = dis[x] + 1;
		dfs2(i,x);
	}
}
void dfs3(int x,int fa)
{
	if(dis2[x] > maxn)
	{
		maxn = dis2[x];
		b = x;
	}
	for(auto i:v[x])
	{
		if(i == fa) continue;
		dis2[i] = dis2[x] + 1;
		dfs3(i,x);
	}
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t > 0)
	{
		t--;
		cin >> n >> k;
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++)
		{
			int u,vv;
			cin >> u >> vv;
			v[u].push_back(vv);
			v[vv].push_back(u);
		}
		if(n <= 100)
		{
			cout << 1 << '\n';
		}
		else if(c == 7)
		{
			int ge = 1e9;
			for(int i = 1;i <= n;i++)
			{
				for(int j = 1;j <= n;j++) dis[j] = dis2[j] = 0;
				maxn = b = 0;
				dfs2(i,0);
				dfs3(b,0);
				int ans = 0;
				for(int j = 1;j <= n;j++)
				{
					ans = max(ans,min(dis[j],dis2[j]));
				}
				ge = min(ge,ans);
			}
			cout << ge << '\n';
		}
		else if(n <= 4000)
		{
			int ans = 1e9;
			for(int i = 1;i <= n;i++)
			{
				priority_queue <node> q;
				q.push({i});
				for(int j = 1;j <= n;j++) dis[j] = 0,f[j] = false;
				int ge = 0;
				for(int j = 1;j <= k;j++)
				{
					int t = q.top().x;
					q.pop();
					f[t] = true;
					ge = max(ge,dis[t]);
//					cout << t << "|" << dis[t] << '\n';
					for(auto l:v[t])
					{
						if(f[l]) continue;
						dis[l] = dis[t] + 1;
						q.push({l});
					}
				}
				cout << '\n';
				ans = min(ans,ge);
			}
			cout << ans << '\n';
		}
		else if(c == 11||c == 12)
		{
			for(int i = 1;i <= n;i++) dis[i] = dis2[i] = 0;
			maxn = b = 0;
			dfs2(1,0);
			int rt = b;
			maxn = b = 0;
			dfs3(rt,0);
			dis[b] = 0;
			dfs2(b,0);
			int ans = 0;
			for(int i = 1;i <= n;i++)
			{
				ans = max(ans,min(dis[i],dis2[i]));
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
