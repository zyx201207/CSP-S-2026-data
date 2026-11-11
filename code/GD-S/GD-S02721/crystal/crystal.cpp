#include<iostream>
#include<cstdio>
#include<algorithm>
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
int n,ans;
long long m,a[500010],s[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for(int l=1,r=1;l<=n;++l)
	{
		r=max(r,l);
		for(;a[r]*(r-l+1)<=m+(s[r]-s[l-1])&&r<=n;++r);
		ans=max(r-l,ans);
	}
	write(ans);
	return 0;
}
