#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	char b[5];
	string c;
	char d[5];
	cin>>a;// ‰»Î 
	for(int i=0;i<3;i++)
	{
		cin>>b[i];
	}
	cin>>c;
	for(int i=0;i<3;i++)
	{
		cin>>d[i];	
	}
	//cout<<a<<b<<c<<d;	
	if(a==c)//≈–∂œ≥µœ· 
	{
		cout<<'1';
	}
	else
	{
		cout<<"0000";
		return 0; 
	}
	if(b[0]==d[0]&&b[1]==d[1])//≈–∂œ≈≈ 
	{
		cout<<'1';
	}
	else
	{
		cout<<"000";
		return 0;
	}
	int m,n;
	m=b[2]-'A';
	n=d[2]-'A';
	//cout<<m<<n;
	if(m>=0&&m<=2)
	{
		if(n>=0&&n<=2)
		{
			cout<<'1';
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	{
		if(n>=3&&n<=4)
		{
			cout<<'1';
		}
		else
		{
			cout<<'00';
			return 0;
		}
	}
	if(m==n+1||m==n-1)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	return 0;
}
