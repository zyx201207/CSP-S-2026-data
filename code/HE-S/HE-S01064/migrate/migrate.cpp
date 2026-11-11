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
	putchar('\n');
}
int cnm,t;
long long n,d,a[2000006],b[2000006],c[2000007],r=1,sum=0;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cnm=read();t=read();
	for(int nm=1;nm<=t;nm++)
	{
		n=read();d=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		r=1;
		for(int l=1;l<=n;l++)
		{
			if(a[n]-a[l]==d)
			{
				b[l]=n;
			}
			if(r==n+1)
			{
				b[l]=r-1;
			}
			while(r<=n)
			{
				if(a[r]-a[l]<=d)
				{
					r++;
				}
				else
				{
					b[l]=r-1;
					break;
				}
			}
		}
		if(2*d>=a[n]-a[1])
		{
			for(r=1;r<=b[1]-1;r++)
			{
				for(int i=b[1]+1;i<=n;i++)
				{
					if(b[r]>=i)
					{
						c[i]++;
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(c[i]==1)
				{
					sum++;
				}
			}
		}
		cout<<sum<<'\n';
	}
}
