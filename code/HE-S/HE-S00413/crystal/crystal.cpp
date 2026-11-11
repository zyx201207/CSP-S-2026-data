#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans=0;
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
	for(int i=2;i<=n;i++)
	{
		int x=m,y=0;
		for(int j=i;j>=1;j--)
		{
			if(a[i]-a[j]<=m)
			{
				x-=(a[i]-a[j]);
				y++;
			}
		}
		ans=max(ans,y);
	}
	cout<<ans;
	return 0;
}
