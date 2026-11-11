#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int cmp(int x)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			x=max(x&a[i],x&a[j]);
		}
	}
	return x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		int t=a[1];
		for(int i=2;i<=n;i++)
		{
			t=t&a[i];
		}
		cout<<t;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans=max(ans,a[i]&a[j]);
		}
	}
	for(int i=2;i<m;i++)
	{
		ans=cmp(ans);
	}
	cout<<ans;
	return 0;
}

