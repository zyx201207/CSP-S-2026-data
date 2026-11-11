#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll T,c,n,d,a[N],ans;
ll read()
{
	ll f=1,s=0;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while (isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return f*s;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	T=read();
	while (T--)
	{
		ans=0;
		n=read();
		d=read();
		for (int i=1; i<=n; i++)
		{
			a[i]=read();
		}
		for (int i=1; i<=n; i++)
		{
			int pd=0;
			if (a[i]-a[i-1]>d)
			{
				continue;
			}
			for (int j=i+2; j<=n; j++)
			{
				if (a[j]-a[j-2]<=d && pd==2)
				{
					break;
				}
				if (pd>0)
				{
					if (a[j]-a[j-2]<=d)
					{
						pd++;
					}
					ans++;
				}
				if (a[j]-a[j-1]>d)
				{
					break;
				}
				if (a[j]-a[j-2]<=d && pd==0)
				{
					pd=1;
					continue;
				}
				
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
