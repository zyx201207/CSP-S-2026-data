#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' or ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int num[1005];
inline void write(int x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	int cnt=0;
	while(x)
	{
		cnt++;
		num[cnt]=x%10;
		x/=10;
	}
	for(int i=cnt;i>=1;i--)
	{
		putchar(num[i]+'0');
	}
}
const int N=5e5+5;
int n,m;
int a[N],s[N],maxx,g;
bool check(int i,int k)
{
	int x=a[k]*(k-i+1);
	int y=s[k]-s[i-1];
	if(x-y<=m) return 1;
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		if(a[i]==a[i-1]) g++;
		else
		{
			maxx=max(maxx,g);
			g=1;
		}
	}
	for(int k=2;k<=n;k++)
	{
		int ans=0;
		int l=1,r=k,i=k;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,k))
			{
				r=mid-1;
				i=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=(k-i+1);
		if(k==n and i==1) ans=n-1;
		maxx=max(maxx,ans);
	}
	write(maxx);
//	printf("%d",maxx);
}
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
