#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum,ans;
	cin>>n>>m;
	long long a[n+3]={0};
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[n];
	for(long long i=n-1;i>=n-m+1;i--)
	{
		ans=(sum&a[i]);
		sum=ans;
	}
	cout<<ans;
	return 0;
}

