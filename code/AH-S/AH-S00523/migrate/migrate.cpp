#include<bits/stdc++.h>
using namespace std;
int read()
{
	long long s=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')flag=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*flag;
}
void write(long long x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
	}
	else
	{
		if(x>9)write(x/10);
		putchar(x%10+'0');
	}
}
long long c,t,n,d,k,cnt;
const int N=2e6+10;
long long x[N],ans;
int main()
{
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	
		while(t--)
		{
			n=read();d=read();
			ans=0;
			for(int i=1;i<=n;i++)x[i]=read();
			long long dd=x[2]-x[1];
			if(dd>d)ans=0;
			else if(d>=dd&&d<dd*2)ans=0;
			else
			{
				cnt=1;
				while(d>=dd*(cnt+1))
				{
					cnt++;
				ans=n-(cnt*2-1);
				if(ans<0){
					ans=0;
					break;
				}
				}
			}
			write(ans);
			puts("");
		}
	
	return 0;
}
