//МпСекї GZ-J00287
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0] == c2[0] && c1[1] == c2[1])
	{
		cout << "1" ;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	if((s1[2] == 'D' && s2[2] != 'F') || (s1[2] == 'F' && s2[2] != 'D') || (s2[2] == 'D' && s1[2] != 'F') || (s2[2] == 'F' && s1[2] != 'D'))
	{
		cout << "00";
		return 0;
	}
	else
	{
		cout << "1";
	}
	char a = s1[2],b = s2[2];
	a+1 == b || a-1 == b ? cout << "1" : cout << "0";
	return 0;
 } 
