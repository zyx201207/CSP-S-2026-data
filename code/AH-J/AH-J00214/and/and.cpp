#include<bits/stdc++.h>
using namespace std;
int n,m;
int read()
{
	int f=1,sum=0;
	char ch=getchar_unlocked();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar_unlocked();
	}
	while(ch>='0'&&ch<='9') 
	{
		sum=sum*10+ch-'0';
		ch=getchar_unlocked();
	}
	return f*sum;
}
void write(int x)
{
	if(x<0)
	{
		putchar_unlocked('-');
		x=-1;
	}
	if(x==0)
	{
		putchar_unlocked('0');
		return ;
	}
	char c[20];
	int sum=0;
	while(x!=0)
	{
		c[++sum]=x%10+'0';
		x/=10;
	}
	for(int i=sum;i>=1;i--) putchar_unlocked(c[i]);
}
long long ans=-0x3f3f3f3f;
int a[200010];
bool b[200010];
void dfs(int dep,long long sum)
{
	if(dep>=m)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			dfs(dep+1,sum&a[i]);
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
	{
		b[i]=1;
		dfs(1,a[i]);
		b[i]=0;
	}
	write(ans);
	return 0;
}
