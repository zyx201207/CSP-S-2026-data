#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],f[500010];
unsigned long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	f[1]=0;
	for (long long i=2;i<=n;i++)
	{
		f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for (long long i=n;i>=1;i--)
	{
		if (f[i]<=m)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}
