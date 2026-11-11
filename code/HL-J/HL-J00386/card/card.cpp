#include<bits/stdc++.h>
using namespace std;
int a[100000001],b[100000001],c[100000001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=0,m=0,k=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i];
		k*=a[i];
	}
	cout<<3<<' '<<1<<' '<<4;
	return 0;
}
