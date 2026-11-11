#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char ch1,ch2;
	bool c;
	cin>>c1>>s1>>ch1>>c2>>s2>>ch2;
	int a=ch1,b=ch2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else cout<<"0";
	if(c1==c2&&s1==s2)
	{
		cout<<"1";
	}
	else cout<<"000";
	if(c1==c2&&s1==s2)
	{
		if((ch1>='A'&&ch1<='C'&&ch2>='A'&&ch2<='C')||(ch1>='D'&&ch1<='F'&&ch2>='D'&&ch2<='F'))
		{
			cout<<"1";
			c=1;
		}
		else cout<<"00";
	}
	if(c==1)
	{
			if(a-b==1||b-a==1)
			{
				cout<<"1";
			}
			else cout<<"0";
	}
	return 0;
}
