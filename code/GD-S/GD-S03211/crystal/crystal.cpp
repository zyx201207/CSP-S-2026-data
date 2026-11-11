#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b,c[1000000],d,e,f=1,g=1;
	cin>>a>>b;
	
	for(int i=0;i<a;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<a;i++)
	{
		for(int j=i+1;j<=a;j++)
	{
		if(c[j]<c[j-1])
		{
			d=c[j];
			c[j]=c[j-1];
			c[j-1]=d;
		}
	} 
	}
	for(int i=a-1;i>=0;i--)
	{
	e=b;
		for(int j=i-1;j>=0;j--)
		{	
			if(c[i]-c[j]<=e)
			{
				e=e-(c[i]-c[j]);
				f++;
			}
			else break;
		}
		if(f>g)g=f;
		f=1;
	}
	cout<<g;
	return 0;
 } 
