#include<bits/stdc++.h>
using namespace std;
long long read()
{
	int fu=1;
	long long res=0;
	char c=getchar();
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
	return fu*res;
}
void write(int x)
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
}
const int N=505,M=5e5+5,D=25,Q=1e5+5;;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read(); 
	}
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		for(int j=1;j<=k[i];j++)
		{
			a[i][j]=read();
			t[i][j]=read();
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		write();
	}
	return 0;
}//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
