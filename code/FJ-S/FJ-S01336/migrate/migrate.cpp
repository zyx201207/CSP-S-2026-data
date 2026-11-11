#include<bits/stdc++.h>//long long
using namespace std;
const long long N=2e6+11,INF=0x7ffffffffffffff;
long long x[N],f[N],g[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long id,T,n,d,last,dan,cnt;
	cin>>id>>T;
	x[0]=-INF;
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(long long i=1; i<=n; i++)
			scanf("%lld",&x[i]);
		last=f[1]=0;
		cnt=0;
		for(long long i=2; i<=n; i++)
		{
			while(x[i]-x[last]>d)
				last++;
			if(last==i)
				g[i]=++cnt;
			else
				g[i]=cnt;
			f[i]=f[last]+1;
		}
		cnt=dan=0;
		for(int i=1; i<=n; i++)
			for(int j=i+3; j<=n; j++)
			{
				if(g[i]==g[j] && f[j]-f[i]==j-i-1)
					dan++;
			}
		printf("%d\n",dan);
	}
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6



*/
