#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long n,m,a[2000005];
long long s(long long a,long long b)
{
	long long sum1=0,sum2=0,d[2000005],f[2000005],c[2000005],dream=0,l=1;
	while(a>0)
	{
		d[++sum1]=a/2;
		a/=2;
	}cout << sum1 << " "<< sum2<<endl;
	while(b>0)
	{
		f[++sum2]=b/2;
		b/=2;
	}
	cout << sum1 << " "<< sum2<<endl;
	long long x=max(sum1,sum2);
	for (int i=1;i<=x;i++)
	{
		if (d[i]==1 && f[i]==1) c[x-i+1]=1;
		else c[x-i+1]=0;
		dream=c[x-i+1]*l+dream;
		l*=2;
	}
	return dream;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n>> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[j]<=a[j+1])swap(a[j],a[j+1]);
		}
	}
	int h=0;
	for (int i=2;i<=m;i++)
	{
		if (a[i]!=a[i-1])h=1;
	}
	if (h==0)
	{
		cout << a[1];
		return 0;
	}
	long long k=1;
	for (int i=1;i<=m;i++)
	{
		s(k,a[i]);
	}
	cout << k;
	return 0;
	fclose(stdin);
	fclose(stdout);	
}
