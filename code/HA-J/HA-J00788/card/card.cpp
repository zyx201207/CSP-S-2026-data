#include<bits/stdc++.h>
using namespace std;
int a[123457];
int b[123456];
int ren[123456];
int asd(int r,int cs)
{
	for(int mm=1;mm<cs;mm++)
	{
		if(r==b[mm])
		{
			return mm;
		}
	}
	return 0;
}
int main()
{
	freopen("cardin","r",stdin);
	freopen("cardout","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int g=1;
	for(int hh=1;hh<=n;hh++)
	{
	for(int i=g;i<=n;)
	{
		g++;
		 b[i]=a[i];
		int r=a[i];
		int yu=asd(r,i);
		if(yu!=0)
		{
			for(int k=yu;k<=i;k++)
			{
				b[k]=0;
			}
			for(int k=1;k<=yu;k++)
			{
				ren[b[k]]+=1;
			}
		}
		
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ren[a[i]];
	}
}
