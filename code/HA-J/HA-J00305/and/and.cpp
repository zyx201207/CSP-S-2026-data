#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100005];
	long long ans;
	cin>>n>>m;
	for(int i =1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i =1;i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{
			ans = max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
}
