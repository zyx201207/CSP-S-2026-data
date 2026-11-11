#include<bits/stdc++.h>
using namespace std;
int a[10005];
int f(int x,int y)
{
	if(x+1)
	{
		return y-2;
	}
	if(x+y)
	{
		return y-y;
	}
	
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<f(n,m);
	return 0;
}
