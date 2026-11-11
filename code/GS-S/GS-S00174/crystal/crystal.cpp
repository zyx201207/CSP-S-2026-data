#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int count=1;
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++)
	{
		long long m1=m;
		int count1=0;
		if(a[i]==a[i-1])
		{
			continue;
		}
		else
		{
			for(int j=i;j>=1;j--)
			{
				if((m1-a[i]+a[j])>=0)
				{
					count1++;
					m1=m1-a[i]+a[j];
				}
				else
				{
					break;
				}
			}
			for(int j=1;j<=n-i;j++)
			{
				if(a[i]==a[i+j])
				{
					count1++;
				}
			}
			count=max(count,count1);
		}
	}
	cout<<count;
	return 0;
}
