#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],s[100001],sum[100001],u,f;
int o,minn=99999;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>5000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			s[i]=abs(a[i]-a[n/2+1]);
		}
		sort(s+1,s+n);
		for(int i=1;i<=n;i++)
		{
			m-=s[i];
			u++;
			if(m<0)
			{
				u--;
				cout<<u;
				return 0;
			}
			if(m==0)
			{
				cout<<u;
				return 0; 
			}
		}
		cout<<u;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum[i]+=abs(a[i]-a[j]);
		}
		if(sum[i]<minn)
		{
			minn=sum[i];
			o=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=abs(a[o]-a[i]);
	}
	sort(sum+1,sum+1+n);
	for(int i=1;i<=n;i++)
	{
		m-=sum[i];
		u++;
		if(m<0)
		{
			u--;
			cout<<u;return 0;
		}
		if(m==0) 
		{
			cout<<u;
			return 0;
		}
	}
	cout<<u;
	return 0;
} 
