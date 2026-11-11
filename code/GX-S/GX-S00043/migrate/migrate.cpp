#include<bits/stdc++.h>
using namespace std;
long long min_,gs,mb,c,t,n,d,sl;
vector<long long> vi;
void dfs(long long xb,long long cd,long long tl)
{
	if(xb==mb)
	{
		if(cd<min_)
		{
			min_=min(min_,cd);
			gs=1;
		}
		else if(cd==min_)
			gs++;
	}
	for(int f=xb+1;f<=mb;f++)
	{
		if(vi[f]-vi[xb]<=tl)
			dfs(f,cd+1,tl-(vi[f]-vi[xb]));
		else if(vi[f]-vi[xb]<=d)
			dfs(f,cd+1,d-(vi[f]-vi[xb]));
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(long long T=0;T<t;T++)
	{
		scanf("%lld%lld",&n,&d);
		vi.resize(n+1);
		for(long long f=1;f<=n;f++)
			scanf("%lld",&vi[f]);
		sl=0;
		for(long long f=3;f<=n-1;f++)
			for(long long o=1;o<=n-f;o++)
			{
				min_=INT_MAX;
				gs=0;
				mb=o+f;
				dfs(o,1,d);
				if(gs==2)
					sl++;
			}
		printf("%lld\n",sl);
	}
	return 0;
}
