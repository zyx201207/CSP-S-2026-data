#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[600000],sum,am,b[600000],mid,l=1,r,q[600000];
bool cmp(int x,int y)
{
	return x>y;
}
bool check(int x)
{
	for(int i=1;i<=n-mid+1;i++)
	{
		sum=0;
		for(int j=i+1;j<=i+mid&&j<=n+1;j++)
		{
			sum+=q[j]-q[i];
			if(sum>m)
			{
				break;
			}
		}
		if(sum<=m)
		{
			return 1;
		}
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i-1]-a[i];
		q[i]=q[i-1]+b[i];
	}
	while(l<r)
	{
		mid=l+((r-l)>>1);
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l-1;
	return 0;	
}
