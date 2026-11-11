#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans;
long long a[500005],s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=a[i]-a[i-1];
	}
	bool fb=1;
	for(int i=1;i<n;i++)
	{
		if(a[i+1]-a[i]!=a[2]-a[1]) fb=0;
	}
	if(n>=100000)
	{
		if(fb)
		{
			for(int i=1;;i++)
			{
				long long sum=(a[1]+a[1+i])*(i+1)/2.0;
				if(sum>m)
				{
					cout<<i+1;
					return 0;
				}
				if(sum==m)
				{
					cout<<i+2;
					return 0;
				}
			}
			return 0;
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		long long mm=m,sum=0;
		for(int j=i-1;j>=1;j--)
		{
			mm-=a[i]-a[j];
			if(mm>=0) sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans+1;
	return 0;
}
