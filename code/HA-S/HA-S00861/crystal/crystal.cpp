#include<bits/stdc++.h>
using namespace std;
long long n,m,mmax;
long long a[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	long long a2[10005]={};
	a2[1]=a[1];
	for(long long i=1;i<=n;i++)
	{
		a2[i]=a[i]+a2[i-1]+m;
		if(a2[i]%i==0) mmax=a2[i]/i/2;
	}
	printf("%d",mmax);
	return 0;
}

