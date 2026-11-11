#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long n,m;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);

	long long cnt=0;
	for(long long j=a[n];j>=a[1];j--)
	{
		long long t=m;
		long long sum=0;
		for(long long i=n;i>=1;i--)
		{
			if(a[i]<=j)
			{
				if(t>=(j-a[i]))
				{
					t-=(j-a[i]);
					sum++;
				}
				else break;
			}
		}
		cnt=max(cnt,sum);
	}
	
	cout<<cnt;
	
	return 0;
}
