#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500002],m;
long long a1[500002][500002];
long long ans[500002];
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			a1[i][j]=a[j]-a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=1;
	}
	long long ans1=0;
	for(int i=1;i<=n;i++)
	{
		ans1=max(ans1,ans[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<'0';
	}
	cout<<ans1;
	return 0;
}