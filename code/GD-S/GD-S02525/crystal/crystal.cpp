#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0;
	long long m=0;
	cin>>n>>m;
	for(long long i=0;i<n;++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	long long num=0;
	long long nmax=0;
	long long sum=m;
	for(long long i=0;i<n;++i)
	{
		long long num=0;
		long long sum=m;
		for(long long j=i;j>=0;--j)
		{
			long long s=arr[i]-arr[j];
			if(s<=sum)
			{
				num+=1; 
				sum-=s;
			}
		}
		if(nmax<num)
		{
			nmax=num;
		}
		if(nmax==n)
		{
			break;
		}
	}
	cout<<nmax;
	return 0;
}
