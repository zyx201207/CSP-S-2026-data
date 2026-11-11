#include<bits/stdc++.h>
using namespace std;
long long a[2000010],f[2000010],s[2000010];
long long ans=0,d;
void ff(int l,int r)
{
	memset(f,63,sizeof(f));
	for(int i=l;i<r;i++)
	{
		f[i]=0;s[i]=1;
		for(int k=i;k<=r;k++)
		{
			for(int j=k+1;a[j]<=a[k]+d&&j<=r;j++)
				if(f[j]>f[k]+1)
				{
					f[j]=f[k]+1;
					s[j]=s[k];
				}
				else if(f[j]==f[k]+1)
					s[j]=s[j]+1;
		}
		for(int j=i;j<=r;j++)
		{
			if(s[j]==2)
				ans++;
			f[j]=f[0];s[j]=0;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%d%lld",&n,&d);
		int t=1;
		scanf("%lld",&a[1]);
		for(int i=2;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]-a[i-1]>d)
			{
				ff(t,i-1);
				t=i;
			}
		}	
		ff(t,n);
		printf("%lld\n",ans);
	}
	return 0;
}
