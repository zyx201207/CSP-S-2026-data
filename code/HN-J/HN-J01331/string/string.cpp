#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],s,ans,sum,l,r;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	s=(s+1)/2;
	l=1;r=n;
	while(l<r)
	{
		if(a[l]<a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
		if(a[l]>a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else
			{
				a[l]-=a[r];
				r--;
			}
		}
		if(a[l]==a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[l];
				l++;
				r--;
			}
			else
			{
				l++;
				r--;
			}
		}
//		cout<<ans<<" ";
	}
	cout<<ans;
	return 0;
}

