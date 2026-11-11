#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long max1=-1,a2,a5,a6;
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
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>max1)
			{
				max1=a[i];
			}
		}
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(i!=j)
				{
					a5=a[i];
					a6=a[j];
					a2=a5 & a6;
				}
				if(a2>max1)
				{
					max1=a2;
				}
			}
		}
		cout<<max1;
	}
	else if(m==n)
	{
		a5=a[1];
		a6=a[2];
		a2=a5 & a6;
		for(int i=3;i<=n;i++)
		{
			a5=a[i];
			a2=a2 & a5;
		}
		cout<<a2;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	return 0;
 } 
