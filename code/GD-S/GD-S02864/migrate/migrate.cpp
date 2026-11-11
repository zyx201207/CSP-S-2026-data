#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,zuo,you,s=0;
	bool f1=true,f2=true;
	long long d;
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%lld",&n,&d);
		for(int j=1;j<=n;j++)
		scanf("%lld",&x[j]);
		zuo=1;
		you=n;
		for(int p=1,q=n;p<q;)
		{
			if(x[p]+d<x[p+1])
			p++;
			else if(x[q]-d>x[q-1])
			q--;
			else
			{
				for(int k=1;k<=n;k++)
				{
					if((x[k]>=x[p]+d)&&f1)
					{
						you=k;
						f1=false;
					}
					if((x[n-k]<=x[q]-d)&&f2)
					{
						zuo=n-k;
						f2=false;
					}
				}
				if(you-zuo==1)
				{
					s++;
					p++;
				}
				else
				q--;
			}
			f1=true;
			f2=true;
		}
		if(n%2==1)
		{
			for(int p=1,q=n;p<q;)
			{
				if(x[p]+d<x[p+1])
				p++;
				else if(x[q]-d>x[q-1])
				q--;
				else
				{
					for(int k=1;k<=n;k++)
					{
						if((x[k]>=x[p]+d)&&f1)
						{
							you=k;
							f1=false;
						}
						if((x[n-k]<=x[q]-d)&&f2)
						{
							zuo=n-k;
							f2=false;
						}
					}
					if(you-zuo==1)
					{
						s++;
						q--;
					}
					else
					p++;
				}
				f1=true;
				f2=true;
			}
		}
		printf("%d\n",s);
		s=0;
		f1=true;
		f2=true;
	}
	return 0;
 } 
