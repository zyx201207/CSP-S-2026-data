#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r",stdin);
	freopen("travel.out","w",stdout);
	string train1, seat1, train2, seat2;
	string num1, num2;
	int c1,c2;
	cin>>train1>>seat1>>train2>>seat2;
	if(train1==train2)
		cout<<"1";
	else
		cout<<"0";
	for(int i=0;i<2;i++)
	{
		int tmp;
		tmp=seat1[i];
		num1+=tmp;
	}
	for(int i=0;i<2;i++)
	{
		int tmp;
		tmp=seat2[i];
		num2+=tmp;
	}
	if(num1==num2&&train1==train2)
		cout<<"1";
	else
		cout<<"0";
	c1=seat1[2];
	c2=seat2[2];
	if((c1>=65&&c1<=67&&c2>=65&&c2<=67)&&num1==num2)
	{
		if(num1==num2&&(c1+1==c2||c1+2==c2||c1+3==c2)||(c1-1==c2||c1-2==c2||c1-3==c2))
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else if((c1>=68&&c1<=69&&c2>=68&&c2<=69)&&num1==num2)
	{
		if(num1==num2&&(c1+1==c2||c1+2==c2)||(c1-1==c2||c1-2==c2))
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
	if((c1>=65&&c1<=67&&c2>=65&&c2<=67)&&num1==num2)
	{
		if((c1+1==c2)||(c1-1==c2))
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else if((c1>=68&&c1<=69&&c2>=68&&c2<=69)&&num1==num2)
	{
		if((c1+1==c2)||(c1-1==c2))
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
	return 0;
}
