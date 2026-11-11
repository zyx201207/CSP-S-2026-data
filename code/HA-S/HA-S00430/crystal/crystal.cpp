#include <bits/stdc++.h>
using namespace std;
long long n,m,ma=LLONG_MIN;
long long a[500000+10],b[500000+10];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		long long ji=1;
		long long temp=m;
		for(int j=i-1;j>=1;j--)
		{
			if(temp>=(a[i]-a[j]))
			{
				temp-=(a[i]-a[j]);
				ji++;
			}
			else
			{
				break;
			}
		}
		if(ma<ji)
		{
			ma=ji;
		}
	}
	cout<<ma;
	return 0;
}
