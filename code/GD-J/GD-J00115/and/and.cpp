#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[200005];
	int f[200005][25];
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=a[1];
	for (int i=2;i<=n;i++)
	{
		sum&=a[i];
	}
	if (m==1) 
	{
		cout<<a[n];
		return 0;
	}
	else if (m==n)
	{
		 cout<<sum;
		 return 0;
	}
	sum=a[n];
	for (int i=n-1,k=m-1;i>=1,k>0;i--,k--)
	{
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
