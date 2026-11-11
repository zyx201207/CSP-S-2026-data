#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum;
int f(int x,int y)
{
	if(x<=m)
	{
		return sum;
	}
	return max(f(x-1,y-1)&a[x],f(x-1,y));
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
	sum=a[1];
	for(int i=1;i<=m;i++)
	{
		sum&a[i];
	}
	cout<<f(n,m);
	return 0;
}
