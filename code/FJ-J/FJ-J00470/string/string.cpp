#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	ll i=0,l=0,r=n-1,ans=0;
	while(l<=r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]>a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else
			{
				ans+=a[l];
				a[r]-=a[l];
				if(a[r]==0)
				r--;
				l++;
			}
		}
		else if(c[l]==c[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else
			{
				a[r]-=a[l];
				if(a[r]==0)
				r--;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
