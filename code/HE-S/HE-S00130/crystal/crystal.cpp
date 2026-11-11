#include<bits/stdc++.h>
using namespace std;
long long n,m,M;
long long a[500005],b[500005],ans,he,k1=INT_MIN,k2=INT_MAX,k3=INT_MIN;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	M=m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		k1=max(a[i],k1);
		k2=min(k2,a[i]);
		k3=max(k3,abs(a[i]));
	}
	if(n>5000&&k3>100000) 
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=b[i-1]+i*(a[i+1]-a[i]);
		}
		for(long long i=1;i<=n-1;i++)
		{
			if(b[i]<=m)
			{
				ans=max(ans,i+1);
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);	
	for(int i=k2;i<=k1;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(a[j]<=i)
			{
				if(M-(i-a[j])>=0)
				{
					ans++;
					M=M-(i-a[j]);
				}
				else
				{
					break;
				}
			}
		}
		he=max(he,ans);
		ans=0;
		M=m;
	}
	cout<<he;
	return 0;
}
