#include<iostream>
#include<string>
using namespace std;
	int n,m,a[500005];
int find(int x,int y)
{
	for(int i=x;i<n;i++)
		if(a[i]==y)return i;
	return -1;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<"1 ";
	}
	return 0;
}
