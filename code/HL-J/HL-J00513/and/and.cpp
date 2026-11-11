#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int mmmax(int x ,int y)
{
	int z=0;
	for(int i=x;i<=n;i++)
	{
		z=max(z,a[i]);
	}
	if(x==0)
	{
		return max(z,y);
	}
	for(int i=x;i<=n;i++)
	{
		y=max(mmmax(x-1,y)&a[i],y&a[i]);
	}
	return y;
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
	cout<<mmmax(m,0);
}
