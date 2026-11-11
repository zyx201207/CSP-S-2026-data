#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const long long N = 5e5+10;
long long nums[N];
long long bian[510][510];
vector<pair<long long int,long long int>> ls[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&m,&n,&d,&q);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",nums+i);
	}
	for(long long i=1;i<=m;i++)
	{
		long long k;
		scanf("%lld",&k);
		for(long long j=0;j<k;j++)
		{
			long long a,b;
			scanf("%lld %lld",&a,&b);
			ls[a].push_back({i,b});
		}
	}
	memset(bian,0x3f,sizeof(bian));
	for(long long i = 1;i<=m;i++) bian[i][i] = 0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<ls[i].size();j++)
		{
			for(long long k = 0;k<j;k++)
			{
				long long u = ls[i][j].first,v=  ls[i][k].first;
				long long val = ls[i][j].second+ls[i][k].second;
				bian[u][v] = min(bian[u][v],val);
				bian[v][u] = min(bian[v][u],val);
			}
		}
	}
	for(long long k = 1;k<=m;k++)
	{
		for(long long i = 1;i<=m;i++)
		{
			for(long long j = 1;j<=m;j++)
			{
				if(bian[i][k]+bian[k][j]<bian[i][j])
				{
					bian[i][j] = bian[j][i] = bian[i][k]+bian[k][j];
				}
			}
		}
	}
	while(q--)
	{
		long long u,v;
		scanf("%lld %lld",&u,&v);
		long long ans = 0x7f7f7f7f7f7f7f7f;
		for(long long i = 0;i<ls[u].size();i++)
		{
			for(long long j = 0;j<ls[v].size();j++)
			{
				if(bian[ls[u][i].first][ls[v][j].first]!=0x3f3f3f3f3f3f3f3f)
				{
					long long dis = bian[ls[u][i].first][ls[v][j].first]+ls[u][i].second+ls[v][j].second;
					ans = min(ans,dis);
				}
			}
		}
		ans+=nums[u]+nums[v];
		printf("%lld\n",ans);
	}
	return 0;
}
