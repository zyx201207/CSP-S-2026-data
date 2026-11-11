#include<bits/stdc++.h>
using namespace std;
string s,s1,ss,s2; 
int a,b;
int c,d;
int get_number(string str)
{
	return (str[0]-'0')*10+str[1]-'0';
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>ss>>s2;
	a=get_number(s),b=get_number(ss);
	if(a==b)
	{
		cout<<1;
		c=get_number(s1),d=get_number(s2);
		if(c==d)
		{
			cout<<1;
			if(s1[2]>='A'&&s1[2]<='C')
			{
				if(s2[2]>='A'&&s2[2]<='C')
				{
					cout<<1;
					int k=abs(s1[2]-s2[2]);
					if(k==1)
					{
						cout<<1;
					}
					else
					{
						cout<<0;
					}
				}
				else
				{
					cout<<"00";
				}
			}
			else
			{
				if(s2[2]>='D'&&s2[2]<='F')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
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
	cout<<endl;
	return 0;
}
