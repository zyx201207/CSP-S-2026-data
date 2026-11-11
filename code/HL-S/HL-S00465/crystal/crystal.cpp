#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b[1000000],m1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	int p=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int p1=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=p1)
		{
			p=0;
			break;
		}
	}
	if(p==1)
	{
		int y=1;
		for(int i=n-1;i>=1;i--)
		{
			if(m1-a[i+1]+a[i]>=0)
			{
				m1=m1-a[i+1]+a[i];
				a[i]=a[i+1];
				y++;
			}
			else
			{
				break;
			}
		}
		cout<<y;
		return 0;
	}
	int x=1;
	for(int i=n;i>=1;i--)
	{
		int y=1;
		for(int j=i-1;j>=1;j--)
		{
			if(m1-a[j+1]+a[j]>=0)
			{
				m1=m1-a[j+1]+a[j];
				a[j]=a[j+1];
				y++;
			}
			else
			{
				break;
			}
		}
		for(int j=i-1;j>=i-1-y;j--)
		{
			a[j]=b[j];
		}
		if(y>x)
		{
			x=y;
		}
		m1=m;
		if(x>=i)
		{
			cout<<x;
			return 0;
		}
	}
	cout<<x;
	return 0;
}