#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b=0,c,d=0;
	int a[1000005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		b=b+i; 
	} 
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<b;j++)
		{
			c=a[i] and a[j];
			if(c>d)
			    d=c;
		}
	}
	cout<<d;
	return 0;
 } 
