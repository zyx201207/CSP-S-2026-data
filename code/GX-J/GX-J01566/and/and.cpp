#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long sum=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<long long>());
	sum=a[1];
	for(long long i=1;i<=m;i++)
	{
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
