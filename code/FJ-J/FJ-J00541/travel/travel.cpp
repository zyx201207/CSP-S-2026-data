#include <iostream>
#include <string> 
#include <cmath> 
using namespace std;
int stringtonum(string s)
{
	int slen=s.length(),num=0,k=1;
	for (int i=slen-1;i>=0;i--) 
	{
		num+=((s[i]-'0')*k);
		k*=10;
	}
	return num;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(stringtonum(c1)==stringtonum(c2)) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	string s1line=s1.substr(0,2),s2line=s2.substr(0,2);
	if(stringtonum(s1line)==stringtonum(s2line)) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	int seat1=(s1[2]-'A'),seat2=(s2[2]-'A');
	if((seat1==3&&seat2==5)||(seat1==5&&seat2==3))
	{
		cout<<"11";
		return 0;
	}
	else
	{
		if(0<=seat1&&seat1<=2&&0<=seat2&&seat2<=2)
		{
			cout<<1;
			if(abs(seat1-seat2)==1)
				cout<<1;
			else
				cout<<0;
			return 0;
		}
		else
			cout<<"00";
	}
	return 0;
} 
