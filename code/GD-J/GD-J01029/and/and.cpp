#include<bits/stdc++.h>
using namespace std;
long long a[200005];
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
	sort(a+1,a+n+1);
	long long sum=a[n];
	for(int i=1;i<m;i++)
	{
		sum=sum&a[n-i];
	}
	cout<<sum;
	return 0;
}
