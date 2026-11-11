#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[200005],sum,n,l=1,nowl=1,ans=0,r=n,nowr=sum;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	nowr=sum;
	while(l<=r)
	{
		nowl+=a[l];
		while(l<=r&&a[l])
		{
			if(c[r]==c[l])
			{
				if(a[l]>=a[r])
				{
					a[l]-=a[r];
					nowr-=a[r];
					a[r]=0;
					r--;
				}
				else
				{
					a[r]-=a[l];
					nowr-=a[l];
					a[l]=0;
				}
			}
			else
			{
				if(a[l]>=a[r])
				{
					a[l]-=a[r];
					nowr-=a[r];
					ans+=a[r];
					a[r]=0;
					r--;
				}
				else
				{
					a[r]-=a[l];
					nowr-=a[l];
					ans+=a[l];
					a[l]=0;
				}
			}
		}
		l++;
	}
	cout<<ans;
	return 0;
}

