#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
constexpr int N=2e6+5;
int C,T,n,to[N],f[N],g[N],h[N];
long long D,a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();T=read();
	for(int TT=1;T--;TT++)
	{
		n=read();D=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1,j=1;i<=n;i++)
		{
			for(;j<=n&&a[i]+D>=a[j];j++);
			to[i]=j-1;
		}
		for(int i=n;i>=2;i--)
			if(to[i-1]<to[i]) g[i]=g[to[i]]+to[i]-to[i-1];
			else g[i]=0;
		for(int i=n;i>=3;i--)
		{
			int num=to[i-2]>=i?to[i-1]-to[i-2]:0;
			if(to[i-1]<to[i]-1) h[i]=f[to[i]],f[i]=f[to[i]]+num;
			else if(to[i-1]==to[i]-1) h[i]=h[to[i]],f[i]=h[to[i]]+num;
			else if(to[i-2]<to[i-1]) h[i]=0,f[i]=g[to[i]]+num;
			else h[i]=0,f[i]=0;
		}
		long long res=0;
		for(int i=1;i<=n;i++)
			if(to[i]>i+1) res+=f[to[i]];
			else if(to[i]==i+1) res+=f[to[i+1]];
		printf("%lld\n",res);
		for(int i=1;i<=n;i++) f[i]=g[i]=h[i]=0;
	}
	return 0;
}
