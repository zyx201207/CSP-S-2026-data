#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool f = false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)
		cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
//	cout<<s1[0]<<" "<<s2[0]<<endl;
//	cout<<s1[1]<<" "<<s2[1]<<endl;
//	cout<<s1[2]<<" "<<s2[2]<<endl;
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}	
	int ss1,ss2;
	if(s1[2]=='F'&&s2[2]=='D')
	{
		cout<<"1";
		f = true;
	}
	else if(s1[2]=='D'&&s2[2]=='F')
	{
		f = true;
		cout<<"1";
	}
	else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
	{
		cout<<"1";
		f = true;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	ss1 = s1[2]-'A';
	ss2 = s2[2]-'A';
	if(ss1-ss1 == 1||ss2-ss1==1)
	{
		if(f)
			cout<<"1";
		else
			cout<<"0";
	}
	else
		cout<<"0";
	return 0;
}
