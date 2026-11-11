#include<bits/stdc++.h>
using namespace std;
long long maxm=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++) 
	{
		long long ans=1;
		long long t=m;
		for(long long j=1;j<i;j++)
		{
			long long y=a[i]-a[j];
			if((t-y)>=0)
			{
				t-=y;
				ans++;
			}
			if(t-y<0)
			{
				break;
			}
		}
		maxm=max(ans,maxm);
	}
	cout<<maxm+1;
	return 0;
}
