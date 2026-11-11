#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],l,r,ans;
char c[200005];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	while(l<=r)
	{
		if (a[l]>a[r])
		{
			if (c[l]!=c[r])
			{
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
	    }
	    else
	    {
	    	if (c[l]!=c[r])
	    	{
	    		ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
