#include<bits/stdc++.h>
using namespace std;
long long T,n,d,ans;
struct ac
{
	long long id,val;
};
vector<ac>edge[2000010];
long long dis[2000010],c[2000010],a[2000010];
bool f[2000010];
long long dij(int st)
{
	memset(dis,0x3f,sizeof dis);
	memset(c,0,sizeof c);
	memset(f,0,sizeof f);
	priority_queue<pair<int,int>>dui;
	dis[st]=0;
	c[st]=1;
	dui.push({0,st});
	while(!dui.empty())
	{
		auto u=dui.top();
		dui.pop();
		if(f[u.second])
		{
			continue;
		}
		f[u.second]=1;
		for(ac v:edge[u.second])
		{
			if(dis[u.second]+v.val<dis[v.id])
			{
				dis[v.id]=dis[u.second]+v.val;
				c[v.id]=c[u.second];
				dui.push({-dis[v.id],v.id});
			}
			else if(dis[u.second]+v.val==dis[v.id])
			{
				c[v.id]+=c[u.second];
			}
		}
	}
	long long cnt=0;
	for(int i=st+1;i<=n;i++)
	{
		if(c[i]==2)
		{
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			edge[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d)
				{
					break;
				}
				edge[i].push_back({j,1});
			}
		}
		for(int i=1;i<n;i++)
		{
			ans+=dij(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
