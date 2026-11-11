#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0,a[200010];
char c[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i]; 
	}
	while(l<r)
	{
		if(a[l]<a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		else
		{
			if(c[l]!=c[r])
			{
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
