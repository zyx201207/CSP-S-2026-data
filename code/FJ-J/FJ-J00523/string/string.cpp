#include<bits/stdc++.h>
using namespace std;
int n;
long long a[1000000],c[1000000],d[1000000],sum=0,num=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	c[0]=0;
	char b[1000000];
	cin>>n;
	d[n+1]=0; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	long long x,y,z;
	x=sum/2;
	for(int i=1;i<=n;i++)
	{
		c[i]+=a[i]+c[i-1];
		if(c[i]+a[i+1]>x)
		{
			y=i;
			break; 
		}
	}
	for(int i=n;i>=1;i--)
	{
		d[i]+=a[i]+d[i+1];
		if(d[i]+a[i-1]>x)
		{
			z=i;
			break; 
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=z;j--)
		{
			if(b[j]==b[i]&&d[j+1]>=c[j]&&d[j-1]<=c[j])num+=c[i]-d[j-1]; 
		}
	} 
	cout<<x-num; 
	return 0;
}
