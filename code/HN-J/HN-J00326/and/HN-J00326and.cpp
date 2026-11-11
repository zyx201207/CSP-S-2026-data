#include<bits/stdc++.h>
using namespace std;
int a[200005],ans;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int s=a[i]&a[j];
			ans=max(ans,s);
		}
	}
	cout<<ans;
	return 0;
}
