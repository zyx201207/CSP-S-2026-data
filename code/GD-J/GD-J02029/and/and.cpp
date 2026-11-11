#include<bits/stdc++.h>
#define int long long
using namespace std;
inline long long read()
{
	long long x=0,f=1;
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
int num[105];
inline void write(int x)
{
	if(!x)
	{
		putchar('0');
		return;
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
const int N=2e5+5;
int n,m,a[N],sum;
bool b[N];
int p[50];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=1;
	}
	for(int j=29;j>=0;j--)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i] and a[i]&(1<<j))
			{
				ans++;
			}
		}
		if(ans<m) continue;
		p[j]=1;
		for(int i=1;i<=n;i++)
		{
			if(!(a[i]&(1<<j)))
			{
				b[i]=0;
			}
		}
	}
	for(int i=29;i>=0;i--)
	{
		if(p[i]) sum+=(1<<i);
	}
	write(sum);
}


