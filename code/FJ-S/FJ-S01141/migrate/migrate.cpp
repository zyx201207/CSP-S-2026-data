#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100,inf=0x3f3f3f3f,MOD=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
ll x[N];int p[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--)
	{
		int n;ll d,e=0;scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++)
		{
			p[i]=max(p[i-1],i);
			while(p[i]<n && x[p[i]+1]-x[i]<=d) p[i]++;
		}
		for(int l=1;l<=n;l++)
		{
			int xx=l;bool b=0;
			for(int r=l+1;r<=n;r++)
			{
				if(p[xx]<r) xx=p[xx];
				if(p[xx]<r) break;
				if(xx==l) continue;
				if(b && p[xx]==r && p[xx-1]>=r) break;
				if(b && p[xx-1]<r) e++;
				if(!b && p[xx-1]>=r && (xx-2<l || p[xx-2]<r)) e++;
				if(!b && p[xx]==r && p[xx-1]>=r && (xx-2<l || p[xx-2]<r)) b=1;
			}
		}
		printf("%lld\n",e);
	}
	return 0;
}
