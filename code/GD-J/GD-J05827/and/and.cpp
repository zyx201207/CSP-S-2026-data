#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long mx=INT_MIN;
	for(long long i=1;i<=n;i++)
	{
		long sum=a[i];
	    for(long long j=1;j<m;j++)
	    {
	    	sum=sum&a[i+j];
		}
		if(sum>mx)
		{
			mx=sum;
		}
	}
	cout<<mx;
	return 0;
 } 
