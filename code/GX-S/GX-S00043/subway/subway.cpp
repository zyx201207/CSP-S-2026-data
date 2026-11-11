#include<bits/stdc++.h>
using namespace std;
struct dtz_
{
	long long w;
	vector<int> hx;
};
long long min_,c,n,m,d,q,y;
vector<long long> vsj;
vector< vector<long long> > dt;
vector<dtz_> dtz;
void dfs(long long x,long long sj)
{
	if(x==y)
	{
		min_=min(min_,sj);
		return;
	}
	for(long long f=1;f<=n;f++)
	{
		if(dtz[x].hx[f]!=-1)
		{
			for(long long o=0;o<(long long)dt[f].size();o++)
			{
				if(sj+dtz[x].hx[f]+dtz[dt[f][o]].hx[f]<vsj[dt[f][o]])
				{
					vsj[dt[f][o]]=sj+dtz[x].hx[f]+dtz[dt[f][o]].hx[f];
					dfs(dt[f][o],vsj[dt[f][o]]);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	dt.resize(n+1,vector<long long>());
	dtz.resize(m+1);
	for(long long f=1;f<=m;f++)
	{
		scanf("%lld",&dtz[f].w);
		dtz[f].hx.resize(n+1,-1);
	}
	for(long long f=1,k;f<=n;f++)
	{
		scanf("%lld",&k);
		dt[f].resize(k);
		for(long long o=0,t;o<k;o++)
		{
			scanf("%lld%lld",&dt[f][o],&t);
			dtz[dt[f][o]].hx[f]=t;
		}
	}
	for(long long f=0,x;f<q;f++)
	{
		scanf("%lld%lld",&x,&y);
		min_=LONG_LONG_MAX;
		vsj.clear();
		vsj.resize(m+1,LONG_LONG_MAX);
		vsj[x]=-1;
		dfs(x,dtz[x].w+dtz[y].w);
		printf("%lld\n",min_);
	}
	return 0;
}
