#include <bits/stdc++.h>
using namespace std;
long long n,a[202020],sum,ans=0,l=1,r;
string c[202020];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(l!=r)
	{
		sum=min(a[l],a[r]);
		if(c[l][0]!=c[r][0]) ans+=abs(sum);
		if(sum==a[r])
		{
			a[l]-=a[r];
			r--;
			continue;
		}
		a[r]-=a[l];
		l++;
	}
	if(c[l][0]!=c[r][0]) ans-=abs(a[l]-a[r]);
	cout<<ans;
	return 0;
}