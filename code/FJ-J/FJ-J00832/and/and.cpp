#include <bits/stdc++.h>
using namespace std;
int rjz(int x)
{
	long long c=0;
	int d=0;
	while(x)
	{
		c+=(x%2)*10*d;
		d++;
		x/=10;
		if(x<=0)
		{
			c+=10*(d+1);
		}
	}
	if(x%2==1)
	{
		c++;
	}
	return c;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[10005];
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<a[n];
	return 0;
}