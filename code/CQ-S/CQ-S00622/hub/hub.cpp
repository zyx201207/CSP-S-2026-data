#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long c,T,n,k,st,tp,res,ans,cnt,vis[1010],dis[1010][1010];
vector<long long>G[100010];
void get_dis(long long u,long long fa,long long dep)
{
	dis[st][u]=dep;
	for(long long v:G[u])
	{
		if(v==fa) continue;
		get_dis(v,u,dep+1);
	}
}
void check(long long u,long long fa,long long last)
{
	if(vis[u]&&!last)
	{
		cnt++;last=1;
	}
	if(!vis[u]&&last) last=0;
	for(long long v:G[u])
	{
		if(v==fa) continue;
		check(v,u,last);
	}
}
void dfs(long long x,long long sum)
{
	if(sum>k) return ;
	if(x==n+1)
	{
		if(sum!=k) return ;
		res=0;cnt=0;check(1,0,0);
		if(cnt>=3)
		{
			return ;
		}
		for(int i=1;i<=n;i++)
		{
			tp=inf;
			for(int j=1;j<=n;j++)
			{
				if(vis[j])
				{
					tp=min(tp,dis[i][j]);
				}
			}
			res=max(res,tp);
		}
		ans=min(res,ans);
		return ;
	}
	vis[x]=1;
	dfs(x+1,sum+1);
	vis[x]=0;
	dfs(x+1,sum);
}


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>T;
	if(c<=3)
	{
		while(T--)
		{
			for(int i=0;i<=n;i++)
			{
				G[i].clear();
				for(int j=0;j<=n;j++)
				{
					dis[i][j]=0;
				}
			}ans=inf;
			cin>>n>>k;
			for(int i=1;i<n;i++)
			{
				long long u,v;
				cin>>u>>v;
				G[u].push_back(v);
				G[v].push_back(u);
			}
			for(int i=1;i<=n;i++)
			{
				st=i;
				get_dis(i,0,0); 
			}
			dfs(1,0);
			cout<<ans<<'\n';
		}
	}
	else if(c==7)
	{
		while(T--)
		{
			for(int i=0;i<=n;i++)
			{
				G[i].clear();
				for(int j=0;j<=n;j++)
				{
					dis[i][j]=0;
				}
			}ans=inf;
			cin>>n>>k;
			for(int i=1;i<n;i++)
			{
				long long u,v;
				cin>>u>>v;
				G[u].push_back(v);
				G[v].push_back(u);
			}
			for(int i=1;i<=n;i++)
			{
				st=i;
				get_dis(i,0,0); 
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					res=0;
					for(int k=1;k<=n;k++)
					{
						res=max(res,min(dis[i][k],dis[j][k]));
					}
					ans=min(ans,res);
				}
			}
			
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
换根DP?
这个两个连通块的限制就让人难受，感觉不好刻画它 
*/
