#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string answer = "";
	bool flag = 1;
	if(c1 == c2)
	{
		answer+='1';
		bool f2 = 1;
		if(s1[0] == s2[0]&&s1[1] == s2[1]) answer+='1';
		else
		{
			answer+='0';
			flag = 0;
			f2 = 0;
		}
		
		if(((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))&&f2 == 1) answer+='1';
		else
		{
			answer+='0';
			flag = 0;
		}
		
		if(flag == 1&&((abs(s1[2]-s2[2]) == 1)&&((s1[2]+s2[2] != 'C'+'D')))) answer+='1';
		else answer+='0';
	}
	else
	{
		answer = "0000";
	}
	cout << answer;
	return 0;
} 
