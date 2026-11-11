#include<iostream>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
int l,r;
char cl,cr;
int ls,rs;
int ans;
inline int read(){char cc=getchar();int z=0,fh=1;while((cc<'0' || cc>'9') && cc!='-'){cc=getchar();}if(cc=='-'){fh=-1;cc=getchar();}while(cc>='0' && cc<='9'){z=z*10+cc-'0';cc=getchar();}return z*fh;}
inline void write(int x){if(x==0){putchar('0');return ;}if(x<0){putchar('-');x=-x;}int z[20],tt=0;while(x){z[++tt]=x%10;x/=10;}for(int i=tt;i;i--){putchar(z[i]+'0');}}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		c[i]=getchar();
		while(c[i]<'a' || c[i]>'z') c[i]=getchar();
	}
	l=1,r=n;
	cl=c[1],cr=c[n];
	ls=a[1],rs=a[n];
	while(l<=r)
	{
		if(cl==cr)
		{
			if(ls<rs)
			{
				rs-=ls;
				cl=c[++l];
				ls=a[l];
			}
			else if(ls==rs)
			{
				cl=c[++l];
				ls=a[l];
				cr=c[--r];
				rs=a[r];
			}
			else
			{
				ls-=rs;
				cr=c[--r];
				rs=a[r];
			}
		}
		else
		{
			if(ls<rs)
			{
				ans+=ls;
				rs-=ls;
				cl=c[++l];
				ls=a[l];
			}
			else if(ls==rs)
			{
				ans+=ls;
				cl=c[++l];
				ls=a[l];
				cr=c[--r];
				rs=a[r];
			}
			else
			{
				ans+=rs;
				ls-=rs;
				cr=c[--r];
				rs=a[r];
			}
		}
	}
	write(ans);
	
	return 0;
}
