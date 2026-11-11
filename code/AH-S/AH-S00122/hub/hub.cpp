#include<bits/stdc++.h>
using namespace std;
const long long N=1000010;
long long ans,c,t,n,k,kkk,jj,x[N],xx,y,ma[15];
bool vis[N];
vector<long long>v[N];
void dfs(long long now,long long no,long long ye)
{
	if(vis[now])
	{
		return ;
	}
	if(!no)
	{
		if(ye)
		{
			dfs(jj,k-kkk,0);
		}
		else
		{
			memset(ma,0,sizeof(ma));
			long long mx=0;
			queue<long long>q;
			for(long long i=1;i<=n;i++)
			{
				if(vis[i])
				{
					q.push(i);
				}
			}
			while(!q.empty())
			{
				long long now=q.front();
				q.pop();
				for(long long i:v[now])
				{
					if(!vis[i]&&!ma[i])
					{
						ma[i]=ma[now]+1;
						q.push(i);
					}
				}
				mx=max(mx,ma[now]);
			}
			ans=min(ans,mx);
		}
		return ;
	}
	vis[now]=1;
	for(long long i:v[now])
	{
		dfs(i,no-1,ye);
	}
	vis[now]=0;
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(long long i=1;i<=n;i++)
		{
			v[i].clear();
		}
		for(long long i=1;i<=n-1;i++)
		{
			cin>>xx>>y;
			v[xx].push_back(y);
			v[y].push_back(xx);
		}
		ans=INT_MAX;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long kk=0;kk<=k;kk++)
				{
					kkk=kk;
					jj=j;
					dfs(i,kk,1);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
