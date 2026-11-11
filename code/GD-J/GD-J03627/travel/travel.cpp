#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	bool f1=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'),f2=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
	if(f1==f2)cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if((!f1)&&(!f2))cout<<1;
	else if(s1[2]=='B'||s2[2]=='B')cout<<1;
	else cout<<0;
	return 0;
}
