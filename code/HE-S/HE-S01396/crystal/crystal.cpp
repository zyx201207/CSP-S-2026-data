#include<bits/stdc++.h>
using namespace std;
int dps(int a[],int ge,int m,int ping)
{
	for(int i=m;i>=0;i--)
	{
		
	}
}
int main()
{
	//	freopen("crystal.in","r",stdin);
	int n,m;
	cin>>n>>m;
	int a[n];
	int ping=0,he=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		he+=a[i];
	}
	ping=round(he/n);
	int ge=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==ping)
		{
			ge++;
		}
		if(a[i]>ping)
		{
			break;
		}
	}
	dps(a,ge,m,ping);
	//	freopen("crystal.out","w",stdout);
}
