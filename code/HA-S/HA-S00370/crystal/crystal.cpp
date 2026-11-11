#include<bits/stdc++.h>
using namespace std;
long long a[500010],c[500010],d[500010];
inline long long read()
{
	long long x=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	if(n>5000)
	{
		int i=a[2]-a[1];long long sum=i;
		while(sum<=m)
		{
			sum+=ans*i;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		int sum=0;
		for(long long j=i;j<=n;j++)
		{
			sum+=(a[j]-a[j-1])*(j-i);
//			cout<<sum<<" ";
			if(sum<=m)
			{
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
long long a[500010],c[500010];
inline long long read()
{
	long long x=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		d[i]=d[i-1]+c[i-1];
	}
	sort(a+1,a+n+1);
	int ssss=0;
	for(long long i=1;i<=n;i++)
	{
		
		int sum=0,r=n;
		while(sum<=m)
		{
			if(sum+(d[mid]-ssss)*(j-i)>m)
			{
				sum+=(d[i]-ssss)*(j-i);
			} 
			else
			{
				sum+=(d[i]-ssss)*(j-i);
			}
		}
//		cout<<sum<<" ";
		ans=max(ans,j-i+1);
		ssss+=c[i];
	}
	cout<<ans;
}*/
