#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans,mid;
int qiuhe(int x)
{
	int sum;
	for(int i=1;i<=x;i++)
	{
		sum+=a[x]-a[i];
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
	if(n%2==1)
	{
		mid=(n+1)/2;
	}
	else
	{
		mid=n/2;
	}
	if(m<qiuhe(mid))
	{
		ans=mid-1;
	}
	else if(m>qiuhe(mid))
	{
		ans=mid+1;
	}
	else
	{
		ans=mid;
	}
	cout<<ans+1;
	return 0;
}
