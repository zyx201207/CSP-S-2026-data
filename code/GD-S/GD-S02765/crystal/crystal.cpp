#include <bits/stdc++.h>
using namespace std;
int a[500005]; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		int x=0;
		for (int j=1;j<=i;j++)
		{
			x+=a[i]-a[j];
		}
		if (x<=m)
		{
			cnt=i;
		}
		else
		{
			break;
		}
	}
	cout<<cnt;
	return 0;
} 
