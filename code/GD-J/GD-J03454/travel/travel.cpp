#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a,c;
	char b,d;
	cin>>a>>b>>c>>d;
	if(a=c)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(b=d)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(a==c&&b==d&&b>'C'&&d>'C')
	{
		cout<<"1";
	}
	else
	{
		if(a==c&&b==d&&b<'C'&&d<'C')
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	if((b=='A'&&d=='B')||(b=='B'&&d=='A')||(b=='C'&&d=='D')||(b=='D'&&d=='C')||(b=='B'&&c=='C')||(b=='C'&&d=='B')||(b=='D'&&d=='E')||(b=='E'&&d=='D')||(b=='E'&&d=='F')||(b=='F'&&d=='E'))
	{
			cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
