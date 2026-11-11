#include <bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	{
		string line1=c1.substr(0,2),line2=c2.substr(0,2);
		//cout<<endl<<line1<<" "<<line2<<endl;
		if(line1==line2)
		{
			cout<<1;
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	
	{
		string num1=c1.substr(2),num2=c2.substr(2);
		if(num1>"C"&&num2>"C")
		{
			cout<<1;
		}
		else if(num1<="C"&&num2<="C")
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
			return 0;
		}
		
		if(abs(num1[0]-num2[0])==1)
		{
			cout<<1;
		}
		else
		{
			//cout<<endl<<num1[0]<<" "<<num2[0]<<endl;
			cout<<0;
			return 0;
		}
	}
	return 0;
}
