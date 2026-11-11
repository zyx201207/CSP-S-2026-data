#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e2;
ll x[N+5];
struct edge
{
	int nxt;
	int to;
}e[N*N+5];
int cnt;
int head[N+5];
void addedge(int u,int v)
{
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
int q[N*N+5];
int dis[N+5],s[N+5];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n;
		ll d;
		scanf("%d%lld",&n,&d);
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			head[i]=0;
			scanf("%lld",&x[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					addedge(i,j);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				s[j]=0;
				dis[j]=0x3f3f3f3f;
			}
			int h=0,t=0;
			q[++t]=i;
			s[i]=1;
			dis[i]=0;
			while(h<t)
			{
				int u=q[++h];
				for(int j=head[u];j;j=e[j].nxt)
				{
					int v=e[j].to;
					if(dis[u]+1<dis[v])
					{
						dis[v]=dis[u]+1;
						s[v]=s[u];
						q[++t]=v;
					}
					else if(dis[u]+1==dis[v])
					{
						s[v]+=s[u];
					}
				}
			}
			for(int j=i+1;j<=n;j++)
			{
				if(s[j]==2)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
