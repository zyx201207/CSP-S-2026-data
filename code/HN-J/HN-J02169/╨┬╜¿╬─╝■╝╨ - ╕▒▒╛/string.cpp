#include <bits/stdc++.h>
using namespace std;
int x,ans;
int f[1000000];
char c[1000000],cc[1000000];
int main()
{
	
	cin>>x;
	
	
	for(int i=1;i<=x;i++)
	{
		cin>>f[i]>>c[i];
	}
	
	for(int i=1;i<=x;i++)
	{
		cc[i]=c[i];
	}
	int y=0;
	for(int i=1;i<=x;i++)
	{
		int n=x;
		y=c[i];
		c[i]=c[n];
		c[n]=y;
		n--;
	}
	
	y=x/2+1;
	for(int i=1;i<=y;i++)
	{
		if(c[i]==cc[i]) ans++; 
	}
	if(ans==y)
	{
		cout<<0;
		return 0;
	}
	else 
	{
		for(int i=ans+1;i<=x;i++)
		{
			y+=f[i];
		}
		cout<<y;
	}
	return 0;
}
