#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,fa[1000005],u[1000005],v[1000005],ans;
bool ff[1000005];
vector<int>a[1000005];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int bfs(int s)
{
	for(int i=1;i<=n;i++)fa[i]=0;
	fa[s]=-1;
	queue<pair<int,int>>q;
	q.push({0,s});
	while(!q.empty())
	{
		int dep=q.front().first,u=q.front().second;
		q.pop();
		if(ff[u]==1)return dep;
		for(int i=0;i<(int)(a[u].size());i++)
		{
			int v=a[u][i];
			if(v==fa[u])continue;
			fa[v]=u;
			q.push({dep+1,v});
		}
	}
	return INT_MAX;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ans=INT_MAX;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			a[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u[i],&v[i]);
			a[u[i]].push_back(v[i]);
			a[v[i]].push_back(u[i]);
		}
		if(c<=3)
		{
			for(int i=(1<<k)-1;i<(1<<n)-1;i++)
			{
				int h=0;
				for(int j=0;j<n;j++)
				{
					ff[j+1]=0;
					if((i>>j)&1)
					{
						h++;
						ff[j+1]=1;
					}
				}
				if(h==k)
				{
					for(int i=1;i<=n;i++)fa[i]=i;
					int siz=0;
					for(int j=1;j<n;j++)
					{
						if(((i>>(u[j]-1))&1)&&((i>>(v[j]-1))&1))
						{
							int uu=find(u[j]),vv=find(v[j]);
							if(uu!=vv)
							{
								fa[uu]=vv;
								siz++;
							}
						}
					}
					if(k-siz<=2)
					{
						int maxx=0;
						for(int i=1;i<=n;i++)
						{
							maxx=max(maxx,bfs(i));
						}
						ans=min(ans,maxx);
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
