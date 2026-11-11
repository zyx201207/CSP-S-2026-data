#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+0,a+n);
	if(n<=5000)
	{
		long long sum=0; 
		for(int i=n-1;i>=0;i--)
		{
			long long q=1;
			long long l=m;
			for(int j=i-1;j>=0;j--)
			{
				if(a[i]-a[j]<=l)
				{
					q++;
					l=l-(a[i]-a[j]);
				}
				else
				{
					break;
				}
			}
			sum=max(sum,q);
		}
		cout<<sum;
		return 0;
	}
	long long l=a[1]-a[0];
	long long h=1;
	long long q=0;
	while(1)
	{
		for(int j=0;j<h;j++)
		{
			q=q+l;
		}
		if(q>m)
		{
			break;
		}
		else
		{
			h++;
		}
	}
	cout<<h;
	return 0;
}

