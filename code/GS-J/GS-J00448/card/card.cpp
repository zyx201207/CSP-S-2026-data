#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	int a[1005][1005];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j];
		}
	}
}
