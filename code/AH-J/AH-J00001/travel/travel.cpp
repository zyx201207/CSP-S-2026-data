#include <bits/stdc++.h>
using namespace std;
string car1,s1,car2,s2;
bool judge1(string st1,string st2)
{
	int len1=st1.size();
	int len2=st2.size();
	if(len1!=len2)return false;
	for(int i=0;i<len1;i++)
		if(st1[i]!=st2[i])return false;
	return true;
}
bool judge2(string st1,string st2)
{
	for(int i=0;i<2;i++)
	{
	   if(st1[i]!=st2[i])return false;
	}
	return true;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>car1>>s1>>car2>>s2;
	if(judge1(car1,car2)==true)cout<<1;
	else return cout<<"0000",0;
	if(judge2(s1,s2)==true)cout<<1;
	else return cout<<"000",0;
	int flag1=0,flag2=0;
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C')flag1=0;
	else if(s1[2]=='D' || s1[2]=='F')flag1=1;
	if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')flag2=0;
	else if(s2[2]=='D' || s2[2]=='F')flag2=1;
	if(flag1==flag2)cout<<1;
	else return cout<<"00",0;
	if(flag1==2 && flag2==2)return cout<<1,0;
	else if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C'))return cout<<1,0;
	else cout<<'0';
	return 0;
}
