#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],sum,d=1;
string c[200001],f; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[1]>>c[1];
	f=c[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(c[i]!=f) d=0;
	}
	if(d==1)
	{
		cout<<0;
		return 0;
	}
	if(n%2==0)
	{
		for(int i=1;i<=n/2;i++)
		{
			if(c[i+n/2]!=c[i])
			{
				sum+=a[i];
				continue;
			} 
			if(c[i+n/2]==c[i]&&a[i]!=a[i+n/2])
			{
				sum+=abs(a[i]-a[i+n/2]);
				continue;
			}
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n/2;i++)
	{
		if(c[i+n/2+1]!=c[i])
		{
			sum+=a[i];
			continue;
		} 
		if(c[i+n/2+1]==c[i]&&a[i]!=a[i+n/2+1])
		{
			sum+=abs(a[i]-a[i+n/2+1]);
			continue;
		}
	}
	cout<<sum;
	return 0;
} 
