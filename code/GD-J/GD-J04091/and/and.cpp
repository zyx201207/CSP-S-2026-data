#include <bits/stdc++.h>
using namespace std;

constexpr bool DEBUG=false;
#define WHENDEBUG if(DEBUG)
#define int long long
#define rd "%lld"

namespace marlin
{
	constexpr int N=2e5+5;
	int n,m;
	using uint = unsigned int;
	uint d[N];
	int c[32][N];
	void flush()
	{
		sort(d,d+n,[&](uint a, uint b)
		{
			return a>b;
		});
		
		for (register int i=0;i<n;i++)
		{
			int x=d[i];
			for (register int j=0;j<32;j++)
			{
				int o=0; if(i) o=c[j][i-1];
				c[j][i]=o+(x&1);
				x>>=1;
			}
		}
	}
	void main()
	{
		scanf(rd rd,&n,&m);
		for (register int i=0;i<n;i++)
		scanf("%llu",d+i);
		flush();
		bool ever=false;
		for (register int w=31;w>=0;w--)
		{
			uint pex=1<<w;
			if (c[w][n-1]<m)
			{
				if (ever) break;
				for (register int i=0;i<n;i++)
				{
					if (d[i]&pex) d[i]&=~pex;
					else break;
				}
				flush();
				continue;
			}
			ever=true;
			if (c[w][n-1]<=m)
			{
				break;
			}
		}
		int ans=d[0];
		for (register int i=1;i<m;i++)
		ans&=d[i];
		printf("%llu",ans);
	}
}

signed main()
{
	WHENDEBUG freopen("and5.in","r",stdin);
	WHENDEBUG{}else freopen("and.in","r",stdin);
	WHENDEBUG{}else freopen("and.out","w",stdout);
	marlin::main();
	return 0; 
}
