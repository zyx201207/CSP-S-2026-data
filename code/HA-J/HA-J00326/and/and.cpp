#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int max,ans;
	for(int i=1;i<=m;i++)
	{
		max=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>max) max=a[j];
		}
		if(i==1) ans=max;
		else ans=ans&max;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==max)
			{
				a[j]=0;
			}
		}
		max=0;
	}
	cout<<ans;
	return 0;
}
