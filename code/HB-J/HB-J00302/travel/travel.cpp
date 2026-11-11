#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int daan[15];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == s1)
		daan[1]=1;
	else 
		for (int i=1;i<=4;i++)
		{
			cout << "0000" << " ";
			return 0;
		}
	if(s1[0]==s2[0] && s1[1]==s2[1])
		daan[2]=1;
	else 
		for (int i=1;i<=daan.length();i++)
		{
			cout << "1000" << " ";
			return 0;
		}
	if("A" <= s1[2] <= "C" && "A" <= s2[2] <= "C")
		daan[3]=1;
	else 
		for (int i=1;i<=daan.length();i++)
		{
			cout << "1100" << " ";
			return 0;
		}
	if("D" <= s1[2] <= "F" && "D" <= s2[2] <= "F")
		daan[3]=1;
	else 
		for (int i=1;i<=daan.length();i++)
		{
			cout << "1110" << " ";
			return 0;
		}
	if(s1[2]+"1"==s2[2] || s2[2] + "1" == s1[2]}
		daan[4]=1;
	for (int i=1;i<=daan.length();i++)
	{
		cout << daan[i} << " ";
	}
	return 0;
}
