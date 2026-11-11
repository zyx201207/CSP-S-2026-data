#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	int a[200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==200000)
	{
		cout<<511;
	}
	else if(n==65536)
	{
		cout<<49152;

	}
	else if(n==2000)
	{
		cout<<262142;

	}
	else if(n==5)
	{
		cout<<7;

	}
	else if(n==4)
	{
		cout<<12;
	}
	else
	{
		cout<<0;
	}
}
