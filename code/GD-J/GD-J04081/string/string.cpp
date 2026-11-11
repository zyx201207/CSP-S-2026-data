#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l,r,lnow,rnow,ans,sum;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	l=0,r=n+1;
	while(l+1<r)
	{
		if(lnow==rnow)
		{
			l++;
			lnow+=a[l];
		}
		else if(lnow<rnow)
		{
			if(c[l+1]!=c[r])
			{
				ans+=min(rnow-lnow,a[l+1]);
			}
			l++;
			lnow+=a[l];
		}
		else if(rnow<lnow)
		{
			if(c[l]!=c[r-1])
			{
				ans+=min(lnow-rnow,a[r-1]);
			}
			r--;
			rnow+=a[r];
		}
	}
	cout<<ans;
	return 0;
}
