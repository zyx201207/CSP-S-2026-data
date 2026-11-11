#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	cout<<'1';
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	cout<<'1';
	else
	{
		cout<<"000";
		return 0;
	}bool f=0;
	for(int i=0;i<3;i++)
	for(int j=i;j<3;j++)
	{
		if(s1[2]==char('A'+i)&&s2[2]==char('A'+j)||s2[2]==char('A'+i)&&s1[2]==char('A'+j))
		{
			cout<<'1';f=1;break;
		}
	}
	if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
	{
		cout<<"11";return 0;
	}
	if(f==0)
	{
		cout<<"00";return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B')
	cout<<'1';
	else
	cout<<'0';
	return 0;
}