#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=(k<<3)+(k<<1)+c-'0';
		c=getchar();
	}
	return k*f;
}
int n;
long long x[2000010],d;
long long minn[2000010];
long long num[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--)
	{
		n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		if(c==11||c==12)
		{
			long long maxg=d/(x[2]-x[1]);
			if(maxg==0||maxg==1)
			{
				printf("0\n");
				continue;
			}
			int ans=max(0ll,1ll*n-maxg*2+1);
			printf("%d\n",ans);
		}
		else
		{
			long long ans=0;
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++) minn[i]=1e18,num[i]=0;
				minn[k]=0;num[k]=1;
				for(int i=k;i<=n;i++)
				{
					if(num[i]==2) ans++;
					if(num[i]==0) break;
					for(int j=i+1;j<=n;j++)
					{
						if(x[j]-x[i]<=d)
						{
							if(minn[i]+1<minn[j])
							{
								minn[j]=minn[i]+1;
								num[j]=num[i];
							}
							else if(minn[i]+1==minn[j])
							{
								num[j]+=num[i];
							}
						}
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
fang T1 shuo bu ding jiu hui le
*/
