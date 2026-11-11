#include<bits/stdc++.h>
using namespace std;
int read()
{
	int res=0,fh=1;
	char ch;
	ch=getchar();
	while(ch<'0' or ch>'9')
	{
		if(ch=='-')fh=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*fh;
}
void printtttt(int x)
{
	if(x>=10)printtttt(x/10);
	putchar(x%10+'0');
	return ;
}
void write(int x,bool hh)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	printtttt(x);
	if(hh)putchar('\n');
	else putchar(' ');
	return ;
}
int c,t;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	t=read();
	for(int i=1;i<=t;i++)write(i,true);
	return 0;
}
