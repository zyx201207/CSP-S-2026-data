#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s=0;
	int sum1=0,sum2=0;
	cin>>n>>m;
	int m1=m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	int s1=s/n;
	int sy=0;
	while(m>0)
	{
		if(a[sy]<s1)
		{
			a[sy]++;
			m--;
		}
		else
			sy++;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==s1)
			sum1++;
	}
	int s2=s/n+1;
	sy=0;
	while(m1>0)
	{
		if(a[sy]<s2)
		{
			a[sy]++;
			m1--;
		}
		else
			sy++;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==s2)
			sum2++;
	}
	cout<<max(sum1,sum2);
	return 0;
} 
