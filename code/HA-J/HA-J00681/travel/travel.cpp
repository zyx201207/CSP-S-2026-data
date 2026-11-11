#include<bits/stdc++.h>
using namespace std;
long long c1,c2,t1,t2,f1,f2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	feropen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2] == 'A') t1 = 1,f1 = 1;
	if(s1[2] == 'B') t1 = 1,f1 = 2;
	if(s1[2] == 'C') t1 = 1,f1 = 3;
	if(s1[2] == 'D') t1 = 2,f1 = 5;
	if(s1[2] == 'F') t1 = 2,f1 = 6;
	
	if(s2[2] == 'A') t2 = 1,f2 = 1;
	if(s2[2] == 'B') t2 = 1,f2 = 2;
	if(s2[2] == 'C') t2 = 1,f2 = 3;
	if(s2[2] == 'D') t2 = 2,f2 = 5;
	if(s2[2] == 'F') t2 = 2,f2 = 6;	
	if(c1 == c2)
	{
		cout<<"1";
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1])
	{
		cout<<"1";
	}
	else 
	{
		cout<<"000";
		return 0;
	}
	if(t1 == t2)
	{
		cout<<"1";
	}
	else 
	{
		cout<<"00";
		return 0;
	}
	if(abs(f1-f2) == 1)
	{
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
