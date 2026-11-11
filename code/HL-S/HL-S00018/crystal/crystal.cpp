#include<bits/stdc++.h>
using namespace std;
long long a[90000005];
long long b[90000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	cout<<m/b[1];
	return 0;
}
