#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[250000];
	int ans[250000];
	ans[0]=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m=1)
	{
		for(int i=1;i<n;i++)
		{
			ans[0]=max(a[i],a[i+1]);
		}
		cout<<ans[0];
		return 0;
	}
	if(m=2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					continue;
				ans[0]=max(ans[0],a[i]&a[j]);
			}
		}
		cout<<ans[0];
		return 0;
	}
	return 0;
}
