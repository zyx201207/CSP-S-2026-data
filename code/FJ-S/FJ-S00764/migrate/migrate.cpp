#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int N=2000000;
long long a[N];
int f[N],g[N],dp1[N],dp2[N],dp3[N],dp4[N];
long long read()
{
	int x;
	char y;
	long long i;
	x=1;
	do
	{
		y=getchar();
		if (y=='-') x=-1;
	}while (y<'0'||y>'9');
	for (i=0;y>='0'&&y<='9';y=getchar()) i=i*10-'0'+y;
	return x*i;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T,n,i,j;
	long long d,ans;
	c=read();
	T=read();
	for (;T;T--)
	{
		n=read();
		d=read();
		for (i=0;i<n;i++) a[i]=read();
		for (i=j=0;i<n;i++)
		{
			for (;j<n-1&&a[j+1]<=a[i]+d;j++);
			f[i]=j; 
		}
		for (i=j=n-1;i>=0;i--)
		{
			for (;j&&a[j-1]>=a[i]-d;j--);
			g[i]=j;
		}
		for (i=0;i<n;i++) dp1[i]=dp2[i]=0;
		for (i=0;i<n;i++) if (f[i]>i) dp1[f[i]]++;
		for (i=0;i<n;i++) if (g[i]<i) dp2[g[i]]++;
		for (i=0;i<n;i++) if (g[i]<i&&f[g[i]]==i) dp1[i]+=dp1[g[i]];
		for (i=n-1;i>=0;i--) if (f[i]>i&&g[f[i]]==i) dp2[i]+=dp2[f[i]];
		for (i=0;i<n-1;i++) dp3[i]=dp4[i]=0;
		for (i=0;i<n;i++) if (f[i]>i+1&&g[f[i]-1]<=i) dp3[f[i]-1]++;
		for (i=0;i<n;i++) if (g[i]<i-1&&f[g[i]+1]>=i) dp4[g[i]]++;
		ans=0;
		for (i=0;i<n-1;i++)
		{
			if (g[i]<i&&f[g[i]]==i+1) dp3[i]+=dp1[g[i]];
			if (f[i+1]>i+1&&g[f[i+1]]==i) dp4[i]+=dp2[f[i+1]]; 
			ans+=(long long)dp3[i]*dp4[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
