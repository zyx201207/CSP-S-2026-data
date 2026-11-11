#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n1,n2;
	string s1,s2;
	cin>>n1>>s1>>n2>>s2;
	if(n1!=n2)
	{
		cout<<"0000";
		return 0;
	}
	else if((s1[0]-48)*10+(s1[1]-48)!=(s2[0]-48)*10+(s2[1]-48))
	{
		cout<<"1000";
		return 0;
	}
	else if(((s1[2]=='F'&&s2[2]!='D')||(s1[2]=='D'&&s2[2]!='F'))||((s1[2]=='A'&&(s2[2]!='B'&&s2[2]!='C'))||(s1[2]=='B'&&(s2[2]!='A'&&s2[2]!='C'))||(s1[2]=='C'&&(s2[2]!='B'&&s2[2]!='A'))))
	{
		cout<<"1100";
		return 0;
	}
	else if(s1[2]-1!=s2[2]&&s1[2]+1!=s2[2])
	{
		cout<<"1110";
		return 0;
	}
	else
	{
		cout<<"1111";
	}
	return 0;
}
