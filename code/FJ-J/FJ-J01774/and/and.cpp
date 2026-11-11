#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<long long>());
	long long u=a[1];
	for(long long i=2;i<=m;i++)
	{
		u&=a[i];
	}
	cout<<u;
	return 0;
}
