#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1e9;
int c,T;
int head[1005],nxt[20005],to[20005],tot=0;
bool vis[10005],flag[100005];
void add(int u,int v)
{
	tot++;
	nxt[tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void dfs(int u)
{
	if(vis[u])
	{
		return;
	}
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(flag[v])
		{
			dfs(v);
		}
	}
}
int res;
void cal(int u,int d)
{
	if(flag[u])
	{
		res=min(res,d);
		return;
	}
	if(vis[u])
	{
		return;
	}
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		cal(v,d+1);
	}
}
void solve()
{
	int n,k;
	scanf("%d%d",&n,&k);
	tot=0;
	for(int i=0;i<n;i++)
	{
		head[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		add(u,v),add(v,u);
	}
	int Ans=INF;
	for(int s=0;s<(1<<n);s++)
	{
		if(__builtin_popcount(s)!=k)
		{
			continue;
		}
		for(int i=0;i<n;i++)
		{
			flag[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			if(s&(1<<i))
			{
				flag[i]=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			vis[i]=0;
		}
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(flag[i]&&!vis[i])
			{
				cnt++; 
				dfs(i);
			}
		}
		if(cnt>2)
		{
			continue;
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(!flag[i])
			{
				for(int j=0;j<n;j++)
				{
					vis[j]=0;
				}
				res=INF;
				cal(i,0);
				ans=max(ans,res);
			}
		}
		Ans=min(Ans,ans);
	}
	printf("%d\n",Ans);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		solve();
	}
	return 0;
}
