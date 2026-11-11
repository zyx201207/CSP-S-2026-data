#include<iostream>
#include<string>
using namespace std;
string a[10],b[10],c[10],d[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=2;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin>>d[i];
	}
		if(a[1]==c[1]&&a[2]==c[2])
		{
			cout<<"1"<<" ";
		}
		else
		{
			cout<<"0"<<" "; 
		}
		if(b[1]==d[1]&&b[2]==d[2])
		{
			cout<<"1"<<" ";
		}
		else
		{
			cout<<"0"<<" ";
		}
		cout<<"0"<<" ";
		cout<<"0"<<" ";
	return 0;
 } 
