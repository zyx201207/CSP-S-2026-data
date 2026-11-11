#include<bits/stdc++.h>
using namespace std;
#define int long long
int read()//long long?
{
	char c=getchar();
	int fu=1,res=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') fu=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res*fu;
}
void write(int x)//long long?
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x<=9)
	{
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
	return;
}
int n;
int a[200005],ans;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		cin>>c[i];
	}
	for(int i=1,j=n;i<j;)
	{
		int minn=min(a[i],a[j]);
		if(c[i]!=c[j])
		{
			ans+=minn;
		}
		a[i]-=minn;
		a[j]-=minn;
		if(a[i]<=0) i++;
		if(a[j]<=0) j--;
	}
	write(ans);
	return 0;
}
