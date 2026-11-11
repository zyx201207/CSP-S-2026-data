#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,flag=1;
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
const int N=5e5+10;
long long n,m,a[N],sum[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	n=read(),m=read();
	//write(n);putchar(' ');write(m);puts("");
	
	for(int i=1;i<=m;i++)write(i),puts("");
	return 0;
}
