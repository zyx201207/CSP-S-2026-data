#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
int main()
{
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long mx=INT_MIN;
	for(long long i=2;i<=n;i++)
	{
		long long sum=m,ans=1;
		for(long long j=i-1;j>0;j--)
		{
			long long c=abs(a[i]-a[j]);
			if(c<=sum)
			{
				sum=sum-c;
				ans++;
			}
			else
			{
				break;
			}
		}
		if(ans>mx)
		{
			mx=ans;
		}
		ans=0;
	}
	cout<<mx;
	return 0;
 } 
