#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long c,T,n,k,u[1000005],v[1000005],d[1000005];
bool vis[1000005];
vector<long long> edge[1000005],to[1000005];
set<long long> s[1000005],s2[1000005];
void dfs(long long rt,long long u,long long f,long long d)
{
	to[rt].push_back(u);
	if(!d)
	{
		return ;
	}
	for(auto v:edge[u])
	{
		if(v!=f)
		{
			dfs(rt,v,u,d-1);
		}
	}
}
bool check(long long x)
{
	for(long long i=1;i<=n;i++)
	{
		to[i].clear();
		dfs(i,i,0,x);
	}
	for(long long t=1;t<=n;t++)
	{
		for(long long i=1;i<=n-1;i++)
		{
			if(i!=t)
			{
				s[u[i]].insert(v[i]),s[v[i]].insert(u[i]);
				d[u[i]]++,d[v[i]]++;
			}
		}
		for(long long i=1;i<=n;i++)
		{
			for(auto v:to[i])
			{
				s2[i].insert(v);
			}
		}
		while(1)
		{
			bool f=0;
			for(long long i=1;i<=n;i++)
			{
				if(vis[i])
				{
					continue;
				}
				if(d[i]<=1)
				{
					bool bj=1;
					for(auto v:to[i])
					{
						if(s2[v].size()<=1)
						{
							bj=0;
							break;
						}
					}
					if(bj)
					{
						if(d[i])
						{
							d[i]--;
							for(auto v:s[i])
							{
								d[v]--;
								s[v].erase(i);
							}
							s[i].clear();								
						}						
						for(auto v:to[i])
						{
							s2[v].erase(i);
						}
						vis[i]=1;
						f=1;
						break;
					}
				}
			}
			if(!f)
			{
				break;
			}
		}
		long long cnt=0;
		for(long long i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				cnt++;
			}
		}
		for(long long i=1;i<=n;i++)
		{
			d[i]=0,vis[i]=0,s[i].clear(),s2[i].clear();
		}	
		if(cnt<=k)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(long long i=1;i<=n-1;i++)
		{
			cin>>u[i]>>v[i];
			edge[u[i]].push_back(v[i]),edge[v[i]].push_back(u[i]);
		}
		long long l=0,r=n-1,ans=n-1;
		while(l<=r)
		{
			long long mid=(l+r)>>1;
			if(check(mid))
			{
				ans=mid;
				r=mid-1;
			}
			else		
			{
				l=mid+1;
			}
		}
		cout<<ans<<endl;
		for(long long i=1;i<=n;i++)
		{
			edge[i].clear();
		}
	}
	return 0;
}
