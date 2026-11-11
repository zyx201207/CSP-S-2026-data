#include<bits/stdc++.h>
using namespace std;

int n,m,a[200010];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<+n;i++)
	{
		cin>>a[i];
	}
	
	int maxy=0;
	
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			maxy=maxy&a[i];
		}
		cout<<maxy;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			maxy=max(maxy,a[i]&a[i+1]);
		}
		cout<<maxy;
		return 0;
	}
	int l=1,r=m+1;
	for(int i=1;i<=n-m;i++)
	{
		int ans=0;
		for(int j=l;j<=r;j++)
		{
			ans=ans&a[l];
		}
		maxy=max(maxy,ans);
		l++;
		r++;
	}
	cout<<maxy;
	return 0;
}
