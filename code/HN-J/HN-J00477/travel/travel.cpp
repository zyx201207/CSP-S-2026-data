#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,s1,s2;
	cin>>a1>>a2>>s1>>s2;
	int aa1,ss1;
	int aa2,ss2;
	char aa3,ss3;
	aa1=a1[0]*10+a1[1];
	ss1=s1[0]*10+s1[1];
	aa2=a2[0]*10+a2[1];
	ss2=s2[0]*10+s2[1];
	aa3=a2[2];
	ss3=s2[2];
	if(aa1!=ss1)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		if(aa2!=ss2)
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<"1";
			if(ss3<='C'&&aa3>'C')
			{
				cout<<"00";
				return 0;
			}
			else if(ss3>'C'&&aa3<='C')
			{
				cout<<"00";
				return 0;
			}
			else
			{
				cout<<"1";
				if(ss3==aa3+1||ss3+1==aa3)
				    cout<<"1";
				else
				    cout<<"0";
			}		
		}	
	}
	return 0;
}
