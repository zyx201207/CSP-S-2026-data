#include <bits/stdc++.h>
using namespace std;

constexpr bool DEBUG=false;
#define WHENDEBUG if(DEBUG)
#define rd "%lld"
#define int long long

namespace marlin
{
	constexpr int N=5e5+5;
	int n,m;
	int d[N],ap[N];
	void main()
	{
		scanf(rd rd,&n,&m);
		d[0]=0;
		for (register int i=1;i<=n;i++)
		scanf(rd,d+i);
		sort(d+1,d+n+1,[&](int a, int b)
		{
			return a<b;
		});
		for (register int i=1;i<=n;i++)
		{
			ap[i]=ap[i-1]+d[i];
		}
		int begine=1,ende=1;
		int ans=0;
		while (ende<=n)
		{
			while (ende<=n+1&&
			(d[ende]*(ende-begine+1)-(ap[ende]-ap[begine-1]))<=m)
				ende++;
			ans=max(ans,ende-begine);
			WHENDEBUG printf("ans. " rd " begine " rd " end " rd "\n",
				ans,begine,ende);
			begine++;
		}
		printf(rd,ans);
	}
}


signed main()
{
	WHENDEBUG freopen("crystal4.in","r",stdin);
	WHENDEBUG{}else freopen("crystal.in","r",stdin);
	WHENDEBUG{}else freopen("crystal.out","w",stdout);
	marlin::main();
	return 0;
}
