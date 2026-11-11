#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int p1,p2,q1,q2;
int x1,x2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	 
	p1=a2[0]-'0';
	p2=a2[1]-'0';
	x1=p1*10+p2;
	q1=b2[0]-'0';
	q2=b2[1]-'0';
	x2=q1*10+q2;
	if(x1!=x2)
	{
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	 
	if('A'<=a2[2]&&a2[2]<='C')
	{
		if('A'<=b2[2]&&b2[2]<='C')
		{
			cout<<"1";
			if(a2[2]=='B'&&b2[2]=='A')cout<<"1";
			else if(a2[2]=='A'&&b2[2]=='B')cout<<"1";
			else if(a2[2]=='B'&&b2[2]=='C')cout<<"1";
			else if(a2[2]=='C'&&b2[2]=='B')cout<<"1";
			else 
			{
				cout<<"0";
				return 0;
			}
			
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	else if('E'<=a2[2]&&a2[2]<='F')
	{
		if('E'<=b2[2]&&b2[2]<='F')
		{
			cout<<"1";
			if(a2[2]=='E'&&b2[2]=='F')cout<<"1";
			else if(a2[2]=='F'&&b2[2]=='E')cout<<"1";
			else 
			{
				cout<<"0";
				return 0;
			}
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	return 0;
}

