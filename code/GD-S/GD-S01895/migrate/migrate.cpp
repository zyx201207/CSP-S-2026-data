#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int inf=1e18;
struct node
{
	int v,w;
};
vector <node> e[N];
bool vis[N];
int d[N],cnt[N];
int a[N];
int n,maxd;
void dijkstra(int s)
{
	priority_queue <pair<int,int>> q;
	for(int i=1;i<=n;i++)
	{
		d[i]=inf;
		cnt[i]=0;
		vis[i]=false;
	}
	d[s]=0;
	q.push({0,s});
	while(q.size())
	{
		auto x=q.top();
		q.pop();
		int u=x.second;
		for(auto to:e[u])
		{
			int v=to.v,w=to.w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				cnt[v]=1;
				q.push({-d[v],v});
			}
			else if(d[v]==d[u]+w) cnt[v]++;
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T,Ts;
	cin>>T>>Ts;
	while(Ts--)
	{
		cin>>n>>maxd;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			e[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=maxd)
				{
					e[i].push_back({j,1});
					e[j].push_back({i,1});
				}
			}
		}
		int ans=0;
		for(int i=1;i<n;i++)
		{
			dijkstra(i);
			for(int j=i+1;j<=n;j++)
			{
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
