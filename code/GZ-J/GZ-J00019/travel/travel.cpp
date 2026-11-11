//GZ-J00019 µËÔÆÐù
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,s1,s2;
	cin >> a1 >> s1 >> a2 >> s2;
	if(a1==a2)
	{
		cout << "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	bool b=1;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			b=0;
		}
	}
	if(b)
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	if((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A'))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	{
		cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
}
