#include<bits/stdc++.h>
using namespace std;
long long a[500005],i,j,n,m,mid;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0)
	{
		mid=n/2;
	}
	else
	{
		mid=n/2+1;
	}
	if(n!=m)
	{
		mid++;
	}
	cout<<mid;
	return 0;
}
