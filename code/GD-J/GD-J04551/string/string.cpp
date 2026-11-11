#include<bits/stdc++.h>
using namespace std;
long long n;
struct T{
	long long x=0,s=0,e=0;
	char c=0;
}a[10000];
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].x>>a[i].c;
		a[i].s=a[i-1].e+1;
		a[i].e=a[i].s+a[i].x;
	}
	for(int i=1;i<=n/2;i++)
	{
		if(a[i].c!=a[n-i+1].c&&a[i].x==a[n-i+1].x)
		{
			sum+=a[i].x;
			a[n-i+1].c=a[i].c;
		}
		else if(a[i].c!=a[n-i+1].c)
		{
			sum+=a[i].x;
			int mx=a[n-i+1].s;
			int my=a[n-i+1].e;
			if(a[i].x<a[n-i+1].x)
			{
				a[n-i].e+=a[n-i+1].x-a[i].x;
				a[n-i+1].s=a[n-i].e+1;
			}
			else
			{
				a[n-i].e-=a[i].x-a[n-i+1].x;
				a[n-i+1].s=a[n-i].e+1;
			}
		}
	}
	cout<<sum;
	return 0;
}

