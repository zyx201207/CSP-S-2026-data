#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2,x1,x2,y1,y2;
char x3,y3;
string ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	for(int i=1;i<a1.size();i++)
	{
	    x1+=a1[i];
	}
	for(int i=1;i<b1.size();i++)
	{
	    y1+=b1[i];
	}
	for(int i=0;i<a2.size()-1;i++)
	{
		if(i==0&&a2[i]!='0'||i!=0)
		{
			x2+=a2[i];
		}
	}
	for(int i=0;i<b2.size()-1;i++)
	{
		if(i==0&&b2[i]!='0'||i!=0)
		{
			y2+=b2[i];
		}
	}
	x3=a2[a2.size()-1];
	y3=b2[b2.size()-1];
	if(x1==y1)
	{
		cout<<"1";
		if(x2==y2)
		{
			cout<<"1";
			if(int(x3)>=65&&int(x3)<=67&&int(y3)>=65&&int(y3)<=67||int(x3)>=68&&int(x3)<=70&&int(y3)>=68&&int(y3)<=70)
			{
				cout<<"1";
				if(int(x3)+1==int(y3)||int(x3)-1==int(y3)||x3=='D'&&y3=='F'||x3=='F'&&y3=='D')
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
