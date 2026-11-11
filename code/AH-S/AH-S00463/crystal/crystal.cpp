#include<bits/stdc++.h>
using namespace std;
long long a[500005],p[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=0;
	for(long long i=1;i<=n;i++)
	{
		p[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<=n;i++)
	{
		sum+=p[i]*(i-1);
		if(sum>m)
		{
			break;
		}
		ans++;
	}
	cout<<ans;
}
