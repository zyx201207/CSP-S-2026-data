#include<iostream>
#include<cstdio>
#include<cctype>
#define int __int128
using namespace std;
const int maxn=2*1e5+5;
int n,ans=0,L=0;
int read()
{
	int num=0,sign=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
			sign=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*sign;
}
void print(int p)
{
	if(p/10)
		print(p/10);
	putchar(p%10+'0');
}
struct S
{
	int l,rest;
	char ch;
}s[maxn];
void solve()
{
	int ls=1,rs=n,ans1=0,ans2=0;
	while(ls<rs)
	{
		int len=min(s[ls].rest,s[rs].rest);
		if(s[ls].ch!=s[rs].ch)
		{
			ans1+=len;	
		}
		s[ls].rest-=len;
		s[rs].rest-=len;
		if(s[ls].rest==0)
			ls++;
		if(s[rs].rest==0)
			rs--;
	}
	ans=ans1;
	return;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		s[i].l=read();
		s[i].rest=s[i].l;
		char tmp=getchar();
		while(tmp<'a' or tmp>'z')
			tmp=getchar();
		s[i].ch=tmp;
		L+=s[i].l;	
	}
	solve();
	print(ans);
	return 0;
}
