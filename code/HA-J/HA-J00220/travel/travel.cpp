#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	//1
	if (a1==b1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";	
	}
	//2
	string a3,a4,b3,b4;
	a3=a2.substr(0,2);
	a4=a2.substr(2,1);
	b3=b2.substr(0,2);
	b4=b2.substr(2,1);
	//a3 01  a4 A
	
	if (a1==b1)
	{
		if (a3==b3)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";	
		}
	}
	else
	{
		cout<<"0";	
	}
	
	//3
	if (a1==b1)
	{
		if (a3==b3)
		{
			if ((a4=="A"||a4=="B"||a4=="C")&&(b4=="A"||b4=="B"||b4=="C"))
			{
				cout<<"1";
			}
			else if ((a4=="D"||a4=="F")&&(b4=="D"||b4=="F"))
			{
				cout<<"1";
			}
			else 
			{
				cout<<"0";
			}
		}
		else 
		{
			cout<<"0";	
		}
	}
	else
	{
		cout<<"0";	
	}
	
	//4
	if (a1==b1)
	{
		if (a3==b3)
		{
			if ((a4=="A"&&b4=="B")||(a4=="B"&&(b4=="A"||b4=="C"))||(a4=="C"&&b4=="B")||(a4=="D"&&b4=="F")||(a4=="F"&&b4=="D"))
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
		else
		{
			cout<<"0";	
		}
	}
	else
	{
		cout<<"0";	
	}
	cout<<endl;
	return 0;
}
