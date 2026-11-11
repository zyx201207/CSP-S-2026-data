#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main()
{
	freopen("travel.in ","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<'1';
	else cout<<'0';
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1])
	{
		cout<<'1';
		if((int)s2[2]==(int)s4[2]+1&&(int)s4[2]!=67||(int)s2[2]+1==(int)s4[2]&&s2[2]!='C')
		{
			cout<<'1';
			cout<<'1';
			return 0;
		}
		else if((int)s2[2]==(int)'C'&&(int)s4[2]=='A'||(int)s4[2]==(int)'C'&&(int)s2[2]=='A')
		{
			cout<<"10";
			return 0;
		}
		else if((int)s2[2]==(int)'D'&&(int)s4[2]==(int)'F'||(int)s4[2]==(int)'D'&&(int)s2[2]==(int)'F')
		{
			cout<<"11";
			return 0;
		}
		else cout<<"00";
	}
	else cout<<"000";
}
