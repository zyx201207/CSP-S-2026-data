#include<iostream>
#include<cstdio> 
#include<vector>
using namespace std;
char *p1,*p2,buf[100000];
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
long long read()
{
	long long f=1,x=0;
	char ch=nc();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=nc();
	}
	while(ch>='0'&&ch<='9')
	{
		x*=10;
		x+=ch-'0';
		ch=nc();
	}
	return f*x;
}
void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
constexpr long long inf=1ll<<60;
int n;
long long d;
vector<long long> p,f;
vector<int> c;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int op=read(),T=read();
	while(T--)
	{
		n=read(),d=read();
		long long ans=0;//其实比爆int先来的是爆时间（ 
		p.assign(n+1,0);//清空中 
		for(int i=1;i<=n;++i) p[i]=read();
		for(int i=n;i;--i)
		{
			f.assign(n+1,inf);
			c.assign(n+1,0);//清空+1
			f[i]=0;
			c[i]=1;
			for(int j=i+1;j<=n;++j)
			{
				for(int k=j-1;k>=i&&p[j]-p[k]<=d;--k)
				{
					int tw=f[k]+1;
					if(tw==f[j])
					{
						c[j]+=c[k];
					}
					if(tw<f[j])
					{
						f[j]=tw;
						c[j]=c[k];
					}
				}
				if(f[j]>=inf) break;
			}
			for(int j=n;j>i;--j)
			{
				if(c[j]==2)
				{
					++ans;
				}
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}//多测记得清空 
