#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5*1e5+5;
int n,m,a[maxn],cnt[maxn],b[maxn];
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
void solve(int start)
{
	int r=0;
	for(int i=start;i<=n;i++)
	{
		int find=-1;
		if(n<=500)
		{
			for(int j=1;j<=r;j++)
				if(b[j]==a[i])
				{
					find=j;
					break;
				}	
		}
		else
		{
			int tmp=lower_bound(b+1,b+1+r,a[i])-b;
			find=(tmp==1+r?-1:tmp);
		}
		if(r!=0 and find!=-1)
			r=find;
		else
			b[++r]=a[i];
	}
	for(int i=1;i<=r;i++)
		cnt[b[i]]++;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		solve(i);
	for(int i=1;i<=m;i++)
		print(cnt[i]),putchar(' ');
	return 0;
}
