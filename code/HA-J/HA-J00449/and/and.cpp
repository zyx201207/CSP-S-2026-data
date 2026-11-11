#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
void write(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>=10) write(x/10);
	putchar((x%10)^48);
}
const int N=200005;
int a[N],n,m;
bitset<N> dp[32],now,tmp;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		for(int j=0;j<=29;j++)
		{
			if((1<<j)&a[i]) dp[j][i]=1;
		}
	}
	int ans=0;
	now.set();
	for(int i=29;i>=0;i--)
	{
		tmp=now&dp[i];
		if(tmp.count()>=m)
		{
			ans+=(1<<i);
			now=tmp;
		}
	}
	write(ans); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
