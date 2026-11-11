#include<bits/stdc++.h>
using namespace std;
long long n,m,s=0,i,j,t,p,q;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000)
	{
		for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=n;i>=1;i--)
	{
		long long t=0;
		for(j=i;j>=1;j--)
		{
			t+=a[i]-a[j];
			if(t>m)
			{
				s=max(s,i-j);
				break;
			}
			if(j==1)s=max(s,i-j+1);
		}
	}
	cout<<s;
	}
	else
	{
		cin>>a[1]>>a[2];
		long long p=a[2]-a[1],q=1;
		for(i=3;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]-a[i-1]!=p)q=0;
		}
		if(q==1)cout<<floor((-p+sqrt(p*p+8*p*m))*1.0/2/p)+1;
		else
		{
			for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=n;i>=1;i--)
	{
		long long t=0;
		for(j=i;j>=1;j--)
		{
			t+=a[i]-a[j];
			if(t>m)
			{
				s=max(s,i-j);
				break;
			}
			if(j==1)s=max(s,i-j+1);
		}
	}
	cout<<s;
		}
	}
return 0;
}
