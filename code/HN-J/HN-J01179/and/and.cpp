#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long sum=a[n];
	for(int i=2;i<=m;i++)
	{
		sum&=a[n+1-i];
	}
	cout<<sum;
	return 0;
}
