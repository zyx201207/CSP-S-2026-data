#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],l[2000005],r[2000005],siz=0,ans=0;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		if(c<=6)
		{
			siz=0;
			for(int i=1;i<=n-3;i++)
			{
				for(int j=i+3;j<=n;j++)
				{
					int ll=i,rr=j,mid;
					while(ll<rr)
					{
						mid=(ll+rr+1)>>1;
						if(x[mid]>x[i]+d)rr=mid-1;
						else ll=mid;
					}
					if(x[ll]+d>=x[j]&&x[ll-2]+d<x[j]&&x[ll-1]+d>=x[j])
					{
						l[++siz]=i;
						r[siz]=j;
					}
				}
			}
			ans=0;
			for(int  i=1;i<=siz;i++)
			{
				int ll=1,rr=1;
				for(int j=l[i];j>=l[i-1]+2;j--)
				{
					if(x[j]-x[j-1]>d)break;
					ll++;
				}
				for(int j=r[i];j<=r[i+1]-2;j++)
				{
					if(x[j+1]-x[j]>d)break;
					rr++;
				}
				ans=ans+ll*rr;
			}
			printf("%lld\n",ans);
		}
	}
	
	return 0;
}
