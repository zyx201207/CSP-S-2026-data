#include<bits/stdc++.h>
using namespace std;
inline long long read();
inline void endl();
inline void kg();
const long long N=5e5+10;
long long a[N],sum[N],ans=1,n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	sum[0]=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i]+sum[i-1]+a[i];
//	cout<<sum[n]<<' ';
	int j=1;
	for(int i=1;i<=n;i++)
	{
		long long num=a[i]*(i-j+1)-(sum[i]-sum[j-1]);
		while(num>m&&j<=i)
		{
			j++;
			num=a[i]*(i-j+1)-(sum[i]-sum[j-1]);
		}
		ans=max(ans,(long long)(i-j+1));
	}
	cout<<ans;

	return 0;
}
inline long long read()
{
	int f=1;
	long long num=0;
	char x=getchar();
	while(x<'0'||x>'9')
	{
		if(x=='-') f=-1;
		x=getchar();
	}
	while('0'<=x&&x<='9')
	{
		num=num*10+(x-'0');
		x=getchar();
	}
	return f*num;
}
inline void endl()
{
	puts("");
	return ;
}
inline void kg()
{
	putchar(' ');
}

