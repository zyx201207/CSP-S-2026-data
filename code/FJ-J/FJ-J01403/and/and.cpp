#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx,o[4];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			a[1]&=a[i];
		}
		cout<<a[1];
		return 0;
	}
	if(m==2)
	{
		long long p=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				p=max(a[i]&a[j],p);
			}
		}
		cout<<p;
		return 0;
	}
	if(maxx<4)
	{
		for(int i=1;i<=n;i++)
		{
			o[a[i]]++;
		}
		for(int i=4;i>=1;i--)
		{
			if(o[i]>=m)
			{
				cout<<i;
				return 0;
			}
			else{
				if(i==3&&maxx==3)
				{
					if(o[3]+o[1]>=m)
					{
						cout<<3;
						return 0;
					}
					if(o[3]+o[2]>=m)
					{
						cout<<2;
						return 0;
					}
				}
				else if(i==2&&maxx==2)
				{
					cout<<0;
					return 0;
				}
				else{
					cout<<1;
					return 0;
				}
			}
		}
	}
	long long sum=a[1];
	for(int i=2;i<=m;i++)
	{
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
