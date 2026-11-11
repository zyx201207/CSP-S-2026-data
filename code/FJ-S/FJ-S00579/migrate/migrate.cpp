#include<iostream>
using namespace std;
long long x[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		long long n,d,s=0;
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(long long u=1;u<n;u++)for(long long v=u+1;v<=n;v++)
		{
			long long y=u,g=u;
			bool rr=1;
			while(y<v&&rr)
			{
				long long p=0;
				while(x[y+p+1]-x[y]<=d&&y+p+1<=v)p++;
				if(p==0)rr=0;
				y+=p;
				g+=y;
			}
			long long z=v,h=v;
			bool ll=1;
			while(z>u&&ll)
			{
				long long p=0;
				while(x[z]-x[z-p-1]<=d&&z-p-1>=u)p++;
				if(p==0)ll=0;
				z-=p;
				h+=z;
			}
			if(ll&&rr&&g!=h&&v-u<=3)s++;
		}
		cout<<s<<endl;
	}
	return 0;
}
