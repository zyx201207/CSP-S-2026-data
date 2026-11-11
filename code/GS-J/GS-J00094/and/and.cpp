#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int n,m,a[200005],b,c;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m>>a[0];
    c=a[0];
    for(int i=1;i<n;i++)
    {
    	cin>>a[i];
    	c&=a[i];
    	b=max(a[i],b);
	}
	if(m==n)
	{
		cout<<c;
		return 0;
	}
	if(m==1)
	{
		cout<<b;
		return 0;
	}
	b=0;
	if(m==2)
	{	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			b=max(b,a[i]&a[j]);
		}
	 } 
	cout<<b;
	return 0;
	}
	if(m==n-1)
	{
		b=0;
		for(int i=0;i<n;i++)
		{
			b=max(b,c&a[i]);
		}
		cout<<b;
	}
	cout<<0;
    return 0;
}
