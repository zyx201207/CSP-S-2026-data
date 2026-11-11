#include<bits/stdc++.h>
using namespace std;
int a[100005],n,m,maxx;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
	}
	cout<<maxx;
	return 0;
}
