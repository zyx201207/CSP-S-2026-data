#include <iostream>
#include <cstdio>
#include <cmath>
long long n,a[200005];
char b[200005],c[200005];
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	bool h=0,k=0;
	cin >> a[1]>>b[1];
	for (long long i=2;i<=n;i++)
	{
		cin >> a[i]>>b[i];
		if (b[i]!=b[i-1]) h=1;
		if (a[i]!=a[i-1]) k=1;
	}
	if (h==0) 
	{
		cout << 0;
		return 0;
	}
	long long sum=0;
	if (k==0)
	{
		for (long long i=1;i<=n/2;i++)
		{
			if (b[i]!=b[n-i+1])sum++;
		}
		cout << sum *a[1];
	}
	long long s=0,t=0;
	if (n<=2000)
	{
		for (long long i=1;i<=n;i++)
		{
			for (long long j=1;j<=a[i];j++)
			{
				c[++s]=b[i];
			}
		}
		for (long long i=1;i<=s/2;i++)
		{
			if (c[i]!=c[s-i+1])
			{
				t++;
			}
		}
		cout << t;
	} 
	return 0;
	fclose(stdin);
	fclose(stdout);	
} 
