#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int C,T;
int n,k;
int en[N<<1],ne[N<<1],h[N],cnt;
inline void add(int a,int b)
{
	en[++cnt]=b;
	ne[cnt]=h[a];
	h[a]=cnt;
}
bool mark[N];
int dis[105][105];
int fa[N];
void dfs(int x,int dad,int u)
{
	fa[x]=dad;
	for(int i=h[x];i;i=ne[i])
	{
		if(en[i]!=dad)
		{
			dis[u][en[i]]=dis[u][x]+1;
			dfs(en[i],x,u);
		}
	}
}
int dad[N];
int getfather(int x)
{
	if(dad[x]==x)return x;
	dad[x]=getfather(dad[x]);
	return dad[x];
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>C>>T;
	while(T--)
	{
		cnt=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)h[i]=0;
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		if(C<=3)
		{
			for(int i=n;i>=1;i--)
			{
				dis[i][i]=0;
				dfs(i,0,i);
			}
			int ans=1e9;
			for(int s=0;s<(1<<n);s++)
			{
				for(int i=1;i<=n;i++)mark[i]=0;
				int cnt=0;
				for(int i=0;i<n;i++)
				{
					if(s>>i&1)
					{
						cnt++;
					}
				}
				if(cnt==k)
				{
					for(int i=1;i<=n;i++)dad[i]=i;
					for(int i=2;i<=n;i++)
					{
						if(s>>(i-1)&1)
						{
							if(s>>(fa[i]-1)&1)
							{
								dad[getfather(i)]=getfather(fa[i]);
							}
						}
					}
					int sl=0;
					for(int i=1;i<=n;i++)
					{
						if((s>>(i-1)&1)&&getfather(i)==i)
						{
							sl++;
						}
					}
					if(sl>2)continue;
					for(int i=1;i<=n;i++)
					{
						if(s>>(i-1)&1)
						{
							mark[i]=1;
						}
					}
					int maxx=0;
					for(int i=1;i<=n;i++)
					{
						int minn=n+1;
						for(int j=1;j<=n;j++)
						{
							if(mark[j])
							{
								minn=min(minn,dis[i][j]);
							}
						}
						maxx=max(maxx,minn);
					}
					ans=min(ans,maxx);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
