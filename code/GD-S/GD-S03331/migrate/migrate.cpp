#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],dis[2000005],vis[2000005],ans[2000005];
vector<int>q[2000005];
queue<int>p;
void spfa(int x)
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(ans,0,sizeof ans);
	while(!p.empty())
	{
		p.pop();
	}
	p.push(x);
	vis[x]=1;
	dis[x]=0;
	ans[x]=1;
	while(p.size())
	{
		x=p.front();
		vis[x]=0;
		p.pop();
		for(auto i:q[x])
		{
			if(dis[i]>dis[x]+1)
			{
				dis[i]=dis[x]+1;
				ans[i]=ans[x];
				if(!vis[i])
				{
					vis[i]=1;
					p.push(i);
				}
			}
			else if(dis[i]==dis[x]+1)
			{
				ans[i]++;
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		long long sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			q[i].clear(); 
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j;j--)
			{
				if(a[i]-a[j]>d)
				{
					break;
				}
				q[i].push_back(j);
				q[j].push_back(i);
			}
		}
		for(int i=1;i<n;i++)
		{
			spfa(i);
			for(int j=i+1;j<=n;j++)
			{
				if(ans[j]==2)
				{
					sum++;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
