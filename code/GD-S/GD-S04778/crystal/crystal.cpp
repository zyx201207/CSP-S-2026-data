#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],ans;
int s(int x,int u)
{
	int sum=0;
	for(int i=n;i>=1;i--)
	{
		if(a[i]>x)
		{
			continue;
		}
		if(u>=(x-a[i]))
		{
			u-=(x-a[i]);
			sum++;
		}
		else
		{
			return sum;
		}
	}
	return sum;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=a[1],r=a[n];
	while(l<=r)
	{
		int mid=(l+r)/2;
		int y=s(mid,m);
		if(y<=ans)
		{
			l=mid+1;
		}
		else
		{
			ans=y;
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
