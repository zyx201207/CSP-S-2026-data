#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
    int num1=int(s1[0]-'0')*10+int(s1[1]-'0');
    int num2=int(s2[0]-'0')*10+int(s2[1]-'0');
    char let1=s1[2],let2=s2[2];
	if(c1==c2) 
	{
		cout<<"1";
	}
	else 
	{
		cout<<"0000"<<endl;
		return 0;
	}
	if(num1==num2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000"<<endl;
		return 0;
	}
	if((let1<='C'&&let2<='C')||(let1>'C'&&let2>'C'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00"<<endl;
		return 0;
	}
	if(abs(int(let1)-int(let2))==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	else
	{
		cout<<"0"<<endl;
		return 0;
	}
	return 0;
}
