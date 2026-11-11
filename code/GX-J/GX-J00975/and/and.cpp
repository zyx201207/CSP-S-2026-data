#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a,b,l,r;
long long n,m;
bool g[200010];
int k[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>k[i];
	}
	sort(k+1,k+n+1);
	for(int i=a;i>=1;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			m=k[i]&k[j];
			if(m>n)
			{
				n=m;
				l=i;
				r=j;
			}
		}
	}
	b-=2;
	g[l]=1;
	g[r]=1;
	for(int i=1;i<=b;i++)
	{
		for(int j=a;j>=1;j--)
		{
			if((n&k[j])>m&&!g[j])
			{
				m=n&k[j];
				r=j;
			}
		}
		g[r]=1;
		n=m;
		m=0;
	}
	cout<<n;
	return 0;
}
