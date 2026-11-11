#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag=0;
	bool flag2=0;
	bool flag3=0;
	bool flag4=0;
	if(c1==c2)
	{
		flag3=1;
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0]&&flag3==1)
	{
		flag4=1;
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(s1[2]=='D'||s1[2]=='F'||s2[2]=='D'||s2[2]=='F')
	{
		flag=1;
		if(s1[2]=='D'&&s2[2]=='F'&&flag3==1&&flag4==1)
		{
			flag2=1;
			cout << 1;
		}
		else if(s1[2]=='F'&&s2[2]=='D'&&flag3==1&&flag4==1)
		{
			flag2=1;
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		if(flag3==1&&flag4==1)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	if(flag==0)
	{
		if(abs(s1[2]-s2[2])==1&&flag3==1&&flag4==1)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		if(flag2==1&&flag3==1&&flag4==1)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	return 0;
}





