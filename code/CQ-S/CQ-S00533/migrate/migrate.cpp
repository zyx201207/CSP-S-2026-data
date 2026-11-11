#include<bits/stdc++.h>
using namespace std;
namespace Ganlai
{
#define int long long
	const int N=2e5+1,INF=9e18;
	int T,n,d,a[N],f[N],dist[N];
	inline int dfs(const int &p,const int &deep)
	{
		if(dist[p]>deep)
			f[p]=0,dist[p]=deep;
		++f[p];
		for(int i=p+1;i<=n;++i)
			if(a[i]-a[p]<=d)
				dfs(i,deep+1);
			else
				break;
	}
	void main()
	{
		scanf("%*d%lld",&T);
		while(T--)
		{
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;++i)
				scanf("%lld",a+i);
			int Ans=0;
			for(int i=1;i<n-2;++i)
			{
				for(int j=i+3;j<=n;++j)
					f[j]=0,dist[j]=INF;
				dfs(i,0);
				for(int j=i+3;j<=n;++j)
					if(f[j]==2)
						++Ans;
			}
			printf("%lld\n",Ans);
		}
	}
#undef int
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	Ganlai::main();
	return 0;
}

