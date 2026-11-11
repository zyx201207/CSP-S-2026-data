#include<bits/stdc++.h>
using namespace std;
int main()
{ 	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2,a,b;
	string s1,s2; 
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='A')
		a=1;
	if(s1[2]=='B')
		a=2;
	if(s1[2]=='C')
		a=3;
	if(s1[2]=='D')
		a=6;
	if(s1[2]=='F')
		a=7;
		

	if(s2[2]=='A')
		b=1;
	if(s2[2]=='B')
		b=2;
	if(s2[2]=='C')
		b=3;
	if(s2[2]=='D')
		b=6;
	if(s2[2]=='F')
		b=7;
	if(c1!=c2)
		cout<<"0000";
	else
	{
		cout<<"1";
		if(s1[0]!=s2[0] or s1[1]!=s2[1])
			cout<<"000";
		else
		{
			cout<<"1";
			if(a+1!=b and a-1!=b and a+2!=b and a-2!=b)
				cout<<"00";
			else
			{
				cout<<"1";
			if(a+1!=b and a-1!=b)
				cout<<"0";
			else
				cout<<"1";
			}	
		}
	}
	return 0;
} 
