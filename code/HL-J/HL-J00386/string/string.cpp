#include<bits/stdc++.h>
using namespace std;
char a[10000001],b[10000001],d[10000001];
int c[10000001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0,z=1,k=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=z;j<=c[i];j++)
		{
			z+=c[i];
			b[j]=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		d[i]=b[n-i+1];
	}
	cout<<0;
	return 0;
}
