#include <iostream>
#include <cmath>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=c1.size()-1;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<=s1.size()-2;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"1000";
			return 0;
		}
	}
	int a1=s1[2]-'A'+'0';
	int a2=s2[2]-'A'+'0';
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='E'))
	{
		cout<<"1100";
		return 0;
	}
	if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='E'))
	{
		cout<<"1100";
		return 0;
	}
	if(abs(a1-a2)!=1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
 */
