#include<iostream>
using namespace std;
long long n,m,a[200001];
long long WOW(long long x)
{
	int y=1;
	for(long long i=2;i<=x;i++)
	{
		y=y*i;
	}
}
int main()
{
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long maxn=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			if(maxn<a[i]&a[j])
			{
				maxn=a[i]&a[j];
			}
		}
	}
	
	cout<<maxn;
	
	return 0;
}
