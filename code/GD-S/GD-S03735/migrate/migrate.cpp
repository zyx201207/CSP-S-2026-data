#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[2000005],f,x[2000005],y[2000005],k,q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		q=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
		{
			long long l=i,r=n+1,mid;
			while(l+1<r)
			{
				mid=(l+r)/2;
				if(a[mid]-a[i]>m)
					r=mid;
				else l=mid;
			}
			x[i]=l;
		}
		for(int i=1;i<=n;i++)
		{
			long long l=0,r=i,mid;
			while(l+1<r)
			{
				mid=(l+r)/2;
				if(a[i]-a[mid]>m)
					l=mid;
				else r=mid;
			}
			y[i]=r;
		}
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				long long xt=x[i],yt=y[j];
				k=0;
				while(xt<yt && !(xt==x[xt] && yt==y[yt]))
				{
					if(x[xt]<=y[yt])
					{
						if(y[x[xt]]!=xt)
							k++;
						if(x[y[yt]]!=yt)
							k++;
					}
					xt=x[xt];
					yt=y[yt];
				}	
				if((y[x[xt]]!=xt || x[y[yt]]!=yt) && xt-yt==1)
					k++;
				if(k==1 && xt<j && yt>i && x[xt]>=yt)
					f++;
			}
		cout<<f<<"\n";
		f=0;
	}
	return 0;
} 
