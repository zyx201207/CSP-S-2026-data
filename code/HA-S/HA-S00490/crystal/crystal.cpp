#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans;
ll a[500005];
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
		long long mul=a[i],nowm=0,ann=0;
		for(int j=i;j>=1;j--)
		{
			if((nowm+mul-a[j])<=m)
			{
				nowm+=mul-a[j];
				ann++;
			}
		}
		if(ann>ans)
		ans=ann;
		ann=0;
		nowm=0;
	}
	cout<<ans;
	return 0;
}
