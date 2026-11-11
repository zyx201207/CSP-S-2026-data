#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0,a[250000];
	char c[250000];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]>=a[r])
			{
				a[l]-=a[r];
				a[r]=0;
			}
			else
			{
				a[r]-=a[l];
				a[l]=0;
			}
		}
		else if(c[l]!=c[r])
		{
			if(a[l]>=a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0;
			}
			else
			{
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0;
			}
		}
		if(a[l]==0)
		{
			l++;
		}
		if(a[r]==0)
		{
			r--;
		}
	}
	cout<<ans;
	return 0;
}
