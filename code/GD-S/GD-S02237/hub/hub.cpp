#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e3+55;
struct node
{
	int val;
	int indeg,maxn;
	int dis[5005];
}a[N];
map<int,int> mp;
vector<int> G[N];
void dfs(int st,int now,int fa,int dep)
{
	a[st].dis[now] = dep;
	a[st].maxn = max(a[st].maxn,dep);
	if(G[now].size() == 1)
	{
		return ;
	}
	for(auto v : G[now])
	{
		if(v != fa)
		{
			dfs(st,v,now,dep + 1);
		}
	}
	return ;
}
int ans[5005];
void dfs2(int st,int now,int fa,int dep)
{
	cout<<st<<endl;
	if(mp[now] == 1)
	{
		ans[st] = min(ans[st],dep);
		return;
	}
	if(G[now].size() == 1)
	{
		return ;
	}
	for(auto v : G[now])
	{
		if(v != fa)
		{
			dfs2(st,v,now,dep + 1);
		}
	}
}
bool cmp(node a,node b)
{
	if(a.indeg == b.indeg)
	{
		return a.maxn < b.maxn;
	}
	return a.indeg > b.indeg;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		mp.clear();
		for(int i = 1;i<=n;i++)
		{
			G[i].clear();
			ans[i] = 1e18;
		}
		for(int i = 1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			a[i].val = i;
			a[x].indeg ++;
			a[y].indeg ++;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		for(int i = 1;i<=n;i++)
		{
			a[i].dis[i] = 0;
			dfs(i,i,-1,0);
		}
		vector<int> de;
		sort(a + 1,a + n + 1,cmp);
		int cnt = 0,gt = 0;
		for(int i = 1;i<=n;i++)
		{
			if(cnt == k)
			{
				break;
			}
			if(de.empty())
			{
				de.push_back(a[i].val);
				cnt ++;
				gt ++;
			}	
			else
			{
				for(auto v : de)
				{
					if(a[i].dis[v] == 1)
					{
						de.push_back(a[i].val);
						cnt ++;
						break;
					}
				}
				if(gt == 2)
				{
					continue;
				}
				else
				{
					gt ++;
					cnt ++;
					de.push_back(a[i].val);
				}
			}
		}
		for(auto v : de)
		{
			mp[v] = 1;
		}
		for(int i = 1;i<=n;i++)
		{
			if(mp[i])
			{
				continue;
			}
			dfs2(i,i,-1,0);
		}
		int answer = 0;
		for(int i = 1;i<=n;i++)
		{
			if(mp[i])
			{
				continue;
			}
			answer = max(answer,ans[i]);
		}
		cout<<answer<<endl;
	}
	return 0;
} 
