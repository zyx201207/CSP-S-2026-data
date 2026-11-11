#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long max1=1;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort (a,a+n);
	for (int i=1;i<n;i++)
	{
		long long sum=1,s=m;
		for (int j=i-1;j>=0;j--)
		{
			if (s>=(a[j+1]-a[j]))
			{
				sum++;
				s-=(a[j+1]-a[j]);
			}
			else break;
		}
		max1=max(sum,max1);
	}
	cout<<max1;
	return 0;
 } 
