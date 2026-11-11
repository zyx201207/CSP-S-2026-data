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
const int N=500005,M=300005;
int a[N],n,q[N],m,lst[M],cnt[M];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	bool flag=1;
	for(int i=1;i<=n;i++) 
	{
		a[i]=read();
		if(i!=1&&a[i-1]>a[i]) flag=0;
	}
	if(n<=5000||(!flag&&n>5000))
	{
		for(int i=1,t=0;i<=n;i++)
		{
			memset(lst,0xff,sizeof(lst));
			t=0;
			for(int j=i;j<=n;j++)
			{
				if(lst[a[j]]!=-1)
				{
					while(q[t]!=a[j])
					{
						lst[q[t]]=-1;
						t--;
					}
					lst[q[t]]=-1;
					t--;
				}
				q[++t]=a[j];
				lst[a[j]]=1;
			}
			for(int j=1;j<=t;j++) cnt[q[j]]++;
		}
		for(int i=1;i<=m;i++) write(cnt[i]),putchar(' ');
		return 0;
	}
	if(flag)
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1]) cnt[a[i-1]]=i-1;
		}
		cnt[a[n]]=n;
		for(int i=1;i<=m;i++) write(cnt[i]),putchar(' ');
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
