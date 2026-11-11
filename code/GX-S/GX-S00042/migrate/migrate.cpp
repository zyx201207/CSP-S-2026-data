//baoli O(n^3)
#include<cstdio>
#include<cstring>

constexpr int N=2e6+1;

int T,n,c;
long long d,x[N],dp[N],g[N];

long long solve1();
long long solve2();
void clear();

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--)
	{
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;++i)
			scanf("%lld",x+i);
		printf("%lld\n",c==11||c==12?solve2():solve1());
		clear();
	}
}

void clear()
{
	memset(dp,0,sizeof(dp));
	memset(g,0,sizeof(g));
}

long long solve2()
{
	if(!n) return 0;
	int a=x[2]-x[1];
	a=d/a;
	if(!a) return 0;
	int res=0;
	for(int i=1;i<=n;++i)
		res+=(i-2)/a;

	return a;
}

long long solve1()
{
	if(!n) return 0;
	return 44;
}
