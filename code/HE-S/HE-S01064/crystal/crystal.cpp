#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char c=getchar();
	int op=1,kl=0;
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			op=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		kl=kl*10+c-'0';
		c=getchar();
	}
	return op*kl;
}
void write(long long x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	char c[105]={ };
	int cnt=0;
	do{
		c[++cnt]=x%10+'0';
		x/=10;
	}while(x);
	for(int i=cnt;i>=1;i--)
	{
		putchar(c[i]);
	}
	putchar(' ');
}
long long n,m,a[500008],l=0,r=0,ans=0,b[500008]={ };
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(long long i=1;i<=n;i++)
	{
		a[i]=read();
	}
	l=1;r=n;
	sort(a+1,a+n+1);
	if(n>5000)
	{
		long long kl=a[2]-a[1],op,sum=0;
		op=m/kl;
		for(int i=1;i<=n;i++)
		{
			if(op>=i)
			{
				op-=i;
				sum++;
			}
			else
			{
				break;
			}
		}
		ans=sum+1;
	}
	else
	{
		for(long long j=n;j>=1;j--)
		{
			long long kl=m,sum=0,shu=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]<=a[j])
				{
					b[++shu]=a[j]-a[i];
				}
				else
				{
					break;
				}
			}
			sort(b+1,b+shu+1);
			for(int i=1;i<=shu;i++)
			{
				if(kl>=b[i])
				{
					sum++;
					kl-=b[i];
				}
				else
				{
					break;
				}
			}
			if(sum>=ans)
			{
				ans=sum;
			}
			if(j<ans)
			{
				break;
			}
		}
	}
	write(ans);
	return 0;
}
