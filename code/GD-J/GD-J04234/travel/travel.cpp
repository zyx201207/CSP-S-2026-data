#include<iostream>
using namespace std;
int main()
{
	int c1,c2,s11,s21;
	char s12,s22;
	cin>>c1>>s11>>s12>>c2>>s21>>s22;
	if(c1==c2)
	{
		cout<<"1";
		if(s11==s21)
		{
			cout<<"1";
			if(((s12<='C')&&(s22<='C'))||((s12>='D')&&(s22>='D')))
			{
				cout<<"1";
				if((s12==s22+1)||(s22==s12+1))
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
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	
	return 0;
}
