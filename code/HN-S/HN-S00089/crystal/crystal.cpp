#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	long long a[100005];
	long long same;
	long long cs=0;
	long long t;
	long long b[1005];
	long long sum=0;
	long long c[10005];
	long long ji;
	long long ans=0;
	long long best;
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++)
	{
			for(int o =0;o<i;o++)
			{
			
				t=a[o+1]-a[o];
				sum=t;
			}	
		c[i]=sum;
	}
	for(int i=1;i<=n;i++)
	{
		if(i<n)
		{
			if(ans<=m)
			{
			for(int o=1;o<=i;o++)
				{
					ans=ans+c[o]*o;	
					best=a[o];
				}
						
						b[i]=ans;
						n--;
			}

				ans=0;
		}
	}

	cout<<n+1;

	return 0;
}
