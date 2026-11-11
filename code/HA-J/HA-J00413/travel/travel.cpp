#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<"1";
	else
		cout<<"0";
	string a=s1.substr(0,2);
	string b=s2.substr(0,2);
	if(a==b && c1==c2)
		cout<<"1";
	else
		cout<<"0";
	if(a==b && c1==c2)
	{
		if(s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D' || s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C')
			cout<<"1";
		else
			cout<<"0";
	}
	else
		cout<<"0";
	if(a==b && c1==c2)
	{
		if(s1[2]=='A' && s2[2]=='B' || s1[2]=='B' && s2[2]=='C' || s1[2]=='D' && s2[2]=='F')
			cout<<"1";
		else
			cout<<"0";
	}
	else
		cout<<"0";
	return 0;
}
