#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[10005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i]>a[i+1])
			{
				int jh=a[i];
				a[i]=a[i+1];
				a[i+1]=jh;
			} 
		}
	}
	int zj=a[n/2+1];int js=0,js2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==zj)
		{
			js2++;
		} 
	} 
	int ls=0;
	for(int i=n/2+1-1;i>=1;i--)
	{
		ls++;
		 if(zj-a[n/2+1-ls]<=m)
		 {
		 	js++;
		 	m-=zj-a[n/2+1-ls];
		 }
		 else
		 {
		 	cout<<js+js2;
		 	return 0;
		 }
	} 
	cout<<js+js2;
	return 0;
} 
