#include<iostream>
using namespace std;
int main()
{
	freopen("crystal.in","r","stdin");
	freopen("crystal.out","w","stdout");
	int n,m,sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a[i];
		cin>>a[i];
	}
	for(int j=1;j<=m;j++)
	{
		if(a[i]<a[i+1])
		{
			a[i]++;
		}
	}
	if(a[i]=a[i+1])
	{
		sum++;
	}
	cout<<sum;
	return 0;
}
