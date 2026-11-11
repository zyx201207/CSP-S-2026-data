#include<bits/stdc++.h>
using namespace std;
#define ll long long

int c,T;
int n;
ll d;
ll a[2000010];
int dis[2000010],cnt[2000010];
vector <int> g[2000010];
ll ans=0;

void bfs(int u)
{
	queue <int> q;
	dis[u]=0;
	q.push(u);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int v:g[now])
		{
			if(dis[v]>dis[now]+1)
			{
				dis[v]=dis[now]+1;
				cnt[v]=1;
				q.push(v);
			}
			else if(dis[v]==dis[now]+1)
			{
				cnt[v]++;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(cnt[i]==2)
		{
			ans++;
//			printf("i=%d\n",i);
		}
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--)
	{
		ans=0;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		if(n<=10000)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]-a[i]<=d)
					{
						g[i].push_back(j);
					}
					else break;
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					dis[j]=1e9,cnt[j]=0;
				bfs(i);
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)
			if(a[i]-a[1]<=d)
			{
				g[1].push_back(i);
			}
			else break;
		for(int j=1;j<=n;j++)
			dis[j]=1e9,cnt[j]=0;
		bfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
