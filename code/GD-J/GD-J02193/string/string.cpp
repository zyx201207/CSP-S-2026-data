#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[200005];
char c[200005];
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<=r)
	{
		if(c[l]!=c[r]) 
		{
			if(a[l]>=a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
				if(a[l]==0) l++;
			}
			else
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
		else 
		{
			if(a[l]>=a[r])
			{
				a[l]-=a[r];
				r--;
				if(a[l]==0) l++;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
