#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and .in","r",stdin);
	freopen("and .out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n);
	int sum=a[n];
	for(int i=1;i<=m-1;i++)
	{
		sum=sum|a[m-i-1];
	}
	cout<<sum;
	return 0;
}
