#include<bits/stdc++.h>
using namespace std;
int c1,c2,ss1,ss2,sss1,sss2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ss1=(s1[0]-'0')*10+s1[1]-'0';
	ss2=(s2[0]-'0')*10+s2[1]-'0';
	sss1=s1[2]-'A'+1;sss2=s2[2]-'A'+1;
	if(c1==c2)
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(ss1==ss2)
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(sss1<=3&&sss2<=3||sss1>3&&sss2>3)
		cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(max(sss1,sss2)-min(sss1,sss2)==1)
		cout<<1;
	else
		cout<<0;
	//Trick||Treat!
	return 0;
}
