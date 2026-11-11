#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,a[500005],c[500005],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		c[i]=c[i-1]+a[i];
	}
	for(int i=2;i<=n;i++)
	{
		ll l=1,r=i;
		while(l<r)
		{
			ll mid=l+(r-l)/2;
			if((i-mid+1)*a[i]-(c[i]-c[mid-1])<=m)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		if(i-r+1>ans)ans=i-r+1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
