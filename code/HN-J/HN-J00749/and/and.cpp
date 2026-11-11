#include <bits/stdc++.h>
using namespace std;
int a[200005],n,m,mx=-1,flaga=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>mx)
			mx=a[i];
		if(a[i]&(a[i]+1))
			flaga=0;
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];		
		}
		cout<<ans;
		return 0;
	}
	if(flaga)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	cout<<0;
	return 0;
}
