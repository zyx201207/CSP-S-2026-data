#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long w[500010];
long long c[500010];
map<int,int>t;
long long n,m,ans=-1,k,o=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n-1;i++)
		if(a[i+1]-a[i]!=a[i]-a[i-1])
		{o=0;break;}
	if(o==1)
	{
		for(int i=2;i<=n;i++)c[i]=c[i-1]+(a[i]-a[i-1])*1ll*(i-1);
		for(int i=1;i<=n;i++)
		{
			if(m<c[i])break;
			k=i;
		}
		printf("%lld",k);
		return 0;
	}
	if((llabs(a[n])+llabs(a[1])<=201)&&(n>5000))
	{
		for(int i=1;i<=n;i++)t[a[i]]++;
		int r=a[1];
		for(int j=a[1];j<=a[n];j++)
		{
			long long u=0;
			if(t[j]!=0)u=t[j];
			long long p=m;
			for(int i=j-1;i>=a[1];i--)
			{
				if(t[i]!=0)
				{
					if((j-i)*t[i]<=p)u=u+t[i],p=p-(j-i)*1ll*t[i];
					else 
					{
						for(int x=t[i];x>=1;x--)
							if((j-i)*x<=p)u=u+x,p=p-(j-i)*1ll*x;
					}
				}
				if(p<j-i)break;
			}
			ans=max(ans,u);
		}
		printf("%lld",ans);
		return 0;
	}
	for(int j=n;j>=1;j--)
	{
		w[j]=1;
		if(j<ans)break;
		long long p=m;
		for(int i=j-1;i>=1;i--)
		{
			if(a[j]-a[i]<=p)
			{
				w[j]++;
				p=p-a[j]+a[i];
			}
		}
		ans=max(ans,w[j]);
	}
	printf("%lld",ans);
	return 0;
}
