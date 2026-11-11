#include<bits/stdc++.h> 
using namespace std;
string rx,ry,xx,xy;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rx>>ry>>xx>>xy;
	string t1=ry.substr(0,2);
	string t2=xy.substr(0,2);
	string t11=ry.substr(2,1);
	string t22=xy.substr(2,1);
	if (rx==xx)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if (t1==t2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	bool f=0;
	if (t11=="A"|| t11=="B" || t11=="C")
	{
		if (t22=="A" || t22=="B"||t22=="C")
		{
			cout<<"1";
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else if (t11=="D"|| t11=="F" )
	{
		if (t22=="D" || t22=="F")
		{
			cout<<"1";
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if (t11=="A"&&t22=="B")
	{
		cout<<"1";
	}
	else if (t11=="B"&&t22=="A")
	{
		cout<<"1";
	}
	else if (t11=="B"&&t22=="C")
	{
		cout<<"1";
	}
	else if (t11=="C"&&t22=="B")
	{
		cout<<"1";
	}
	else if (t11=="D"&&t22=="F")
	{
		cout<<"1";
	}
	else if (t11=="F"&&t22=="D")
	{
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
