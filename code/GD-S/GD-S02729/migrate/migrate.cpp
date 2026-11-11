#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const long long N = 2e6+10;
long long nums[N];
long long vis[N][2],cnt;
long long n,d;
long long bfs(long long s)
{
	memset(vis,0,sizeof(vis));
	vis[s][0] = 1,vis[s][1] = 0;
	queue<int> q;
	q.push(s);
	long long ds = 0;
	while(q.size())
	{
		ds++;
		long long qn = q.size();
		while(qn--)
		{
			long long id = q.front();
			for(long long i=id;i<=n;i++)
			{
				if(nums[i]-nums[id]>d) break;
				if(!vis[i][0])
				{
					vis[i][1] = ds;
					q.push(i);
				}
				if(vis[i][1] == ds)
				{
					vis[i][0] += vis[id][0];
				}
			}
			q.pop();
		}
	}
	for(long long i=1;i<=n;i++)
	{
		if(vis[i][0] == 2) cnt++;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	scanf("%lld %lld",&c,&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&d);
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",nums+i);
		}
		for(long long i=1;i<=n;i++)
		{
			bfs(i);
		}
		printf("%lld\n",cnt),cnt = 0;
	}
	return 0;
}
