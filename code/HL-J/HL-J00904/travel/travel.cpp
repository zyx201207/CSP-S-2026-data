#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[101][101],b[101][101];
int main()
{
	freopen("and.in","stdin");
    freopen("and.out","stdout");
	int n,s,k,o;
	cin>>n>>s>>k>>o;
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
	{
		cin>>a[i][j]>>b[i][j];
	}
	}
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
	{
	if(a[i][j]=b[i][j])
	cout<<1<<" ";
	else
	cout<<0<<" ";
	}
	}
	while(a[i]!=01)
	(	cout<<1<<" ";
	else
	cout<<0<<" ";)
	}		
	return 0;
}