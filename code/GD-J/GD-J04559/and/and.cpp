#include <bits/stdc++.h> 
using namespace std;
long long m,n,a[200010],b;
long long apple(long long x,long long y)
{
	for (long long i=x;i<=n-y;i++)
	{
		if (y==0)
		{
			return a[i];
		}
		else
		{
			return a[i]&apple(i+1,y-1);
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	b=m;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<apple(1,m);
	return 0;
}
