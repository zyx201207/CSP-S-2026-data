#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			long long t;
			if(i==1) t=a[2];
			else t=a[1];
			for(int j=2;j<=n;j++)
				if(i!=j) t=t&a[j];
			ma=max(ma,t);
		}
		cout<<ma;
		return 0;
	}
	ma=a[n];
	for(int i=n-1;i>=n-m+1;i--) ma=ma&a[i];
	cout<<ma;
	return 0;
}
