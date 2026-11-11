#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10001],m,s=0;
	string b[10001];
	string n="",p="";
	cin>>m;
	for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			n+=b[i];
		}
	}
	for(int i=m;i>=1;i--)
	{
		for(int j=a[i];j>=1;j--)
		{
			p+=b[i];
		}
	}
	if(p==n) 
	{
		cout<<0;
		return 0;
	}
	
	return 0;
}
