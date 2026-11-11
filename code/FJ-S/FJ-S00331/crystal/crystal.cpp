#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],l=1,r,b[500005];
int read()
{
	char c=getchar();
	int f=1,x=0;
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
void write(int x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10+'0'); 
}
bool check(int x)
{
	for(int i=1;i<=n-x+1;i++)
		if((x-1)*a[i+x-1]-b[i+x-2]+b[i-1]<=m)
			return true;
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	write(l);
}
