#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s3,s4,s5,s6;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int len1=s1.size();
	int len2=s2.size();
	s3=s1.substr(0,len1-1);
	s4=s2.substr(0,len2-1);
	s5=s1.substr(2,1);
	s6=s2.substr(2,1);
	if(c1==c2)
	{
		cout<<"1";
	}	
	else
	{
		cout<<"0000";
		return 0;
	} 
	if(s3==s4)
	{
		cout<<"1";
	}	
	else
	{
		cout<<"000";
		return 0;
	} 
	if((s5=="D"&&s6=="C")||(s6=="D"&&s5=="C"))
	{
		cout<<"0";
	} 
	else cout<<"1";
	if((s5=="A"&&s6=="B")||(s6=="A"&&s5=="B")) 
	{
		cout<<"1";
		return 0;
	}
	else 
	{
		cout<<"0";
		return 0;
	}		
	if((s5=="B"&&s6=="C")||(s5=="C"&&s6=="B")) 
	{
		cout<<"1";
		return 0;
	}
	else 
	{
		cout<<"0";
		return 0;
	}
	if((s5=="D"&&s6=="E")||(s5=="E"&&s6=="D")) 
	{
		cout<<"1";
		return 0;
	}
	else 
	{
		cout<<"0"; 
		return 0;
	}
	if((s5=="E"&&s6=="F")||(s5=="F"&&s6=="E"))
	{
		cout<<"1";
		return 0;
	}
	else 
	{
		cout<<"0";
		return 0;
	}
	return 0;
}
