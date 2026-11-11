#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<i;
	}
	return 0;
} 
