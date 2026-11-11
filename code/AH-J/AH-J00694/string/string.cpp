#include<bits/stdc++.h>
using namespace std;
long long a[500005];
char c[500005];
long long n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r)
	{
		long long s=min(a[l],a[r]);
		if(c[l]!=c[r])
		{
			ans=ans+s;
		}
		a[l]-=s;
		a[r]-=s;
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
